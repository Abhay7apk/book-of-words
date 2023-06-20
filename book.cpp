#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>  // Added header

// Function to split a string into words
std::vector<std::string> splitString(const std::string& str) {
    std::istringstream iss(str);
    std::vector<std::string> words(std::istream_iterator<std::string>{iss},  // Added std:: prefix
                                   std::istream_iterator<std::string>());   // Added std:: prefix
    return words;
}


// Function to generate the index
std::map<std::string, std::set<int>> generateIndex(const std::vector<std::string>& pageFiles,
                                                   const std::string& excludeWordsFile) {
    std::map<std::string, std::set<int>> index;

    // Load exclude words
    std::set<std::string> excludeWords;
    std::ifstream excludeWordsStream(excludeWordsFile);
    if (excludeWordsStream.is_open()) {
        std::string word;
        while (excludeWordsStream >> word) {
            excludeWords.insert(word);
        }
        excludeWordsStream.close();
    }

    // Process page files
    for (int i = 0; i < pageFiles.size(); i++) {
        std::ifstream pageStream(pageFiles[i]);
        if (pageStream.is_open()) {
            std::string line;
            int lineNumber = 1;
            while (std::getline(pageStream, line)) {
                std::transform(line.begin(), line.end(), line.begin(), ::tolower); // Convert to lowercase
                std::vector<std::string> words = splitString(line);
                for (const std::string& word : words) {
                    // Exclude words and punctuation
                    if (excludeWords.find(word) == excludeWords.end() && word.find_first_not_of("abcdefghijklmnopqrstuvwxyz") == std::string::npos) {
                        index[word].insert(i + 1);
                    }
                }
                lineNumber++;
            }
            pageStream.close();
        }
    }

    return index;
}

// Function to print the index
void printIndex(const std::map<std::string, std::set<int>>& index) {
    for (const auto& entry : index) {
        std::cout << entry.first << " : ";
        bool first = true;
        for (const int pageNumber : entry.second) {
            if (!first) {
                std::cout << ",";
            }
            std::cout << "Page " << pageNumber;
            first = false;
        }
        std::cout << std::endl;
    }
}

int main() {
    // Define the page files and exclude words file
    std::vector<std::string> pageFiles = {"Page1.txt", "Page2.txt", "Page3.txt"};
    std::string excludeWordsFile = "exclude-words.txt";

    // Generate the index
    std::map<std::string, std::set<int>> index = generateIndex(pageFiles, excludeWordsFile);

    // Print the index
    printIndex(index);

    return 0;
}
