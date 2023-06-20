# book-of-words
Assignment work
logic behind :
The logic behind the program is as follows:

The program aims to read a given file (book.txt) and create a mapping of word-page numbers for each line.

To achieve this, the program takes the following steps:

1. It utilizes a helper function called `splitString` to split each line into words. This function creates a vector of words by dividing the string based on spaces and tabs.

2. Inside the `main` function, a map named `index` is created. This map will store the word-page number mapping.

3. The program opens the file and reads it line by line using the `getline` function.

4. For each line, the `splitString` function is called to obtain a vector of words.

5. The program iterates over each word in the vector and updates the `index` map accordingly. Each word is used as a key in the map, and the corresponding page number is inserted into the set associated with that word.

6. After processing each line, the page number is incremented.

7. Finally, a set named `excludeWords` is created, which contains certain words that are to be excluded from the word-page number mapping.

The program outputs the word-page number mapping for the specified pages (1, 2, 3) while excluding the words specified in the `excludeWords` set.
 ***** PLEASE PLEASE DO TELL IF IT NEEDS IMPROVEMENT AND ANYTHING I DID WRONG *****
PLEASE CHANGE THE PATH AND FILE NAME TO THE FILE INCLUDED ACCORDING TO YOUR SETUP .
