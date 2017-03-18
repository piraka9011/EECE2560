/**
	EECE2560: Proj3a
	main.cpp
	Purpose: The main file implements the findMatches and search functions.
    These functions get all possible words in the dictionary and check to
    see if they are an actual word. It then prints all found words.
	@author: Anas Abou Allaban & Turki Alrifaie
	@version: 1.0 3/13/17
*/
#include "Dictionary.h"
#include "Grid.h"

/**
    A function to simplify the process of obtaining a word from the switch case.
    Checks the boundaries of the grid and ensure a wrap is made. It returns
    the complete word
    @param  int x: Position x in the grid
            int y: Position y in the grid
            matrix<char> grid: The grid that contains the char matrix
            string word: Our temp word
    @return string word: Our temp word with an added character according to position
 */
std::string getWord(int& x, int& y, matrix<char> grid, std::string word) {
    // If col is negative, goto end of col
    if (x == -1)
        x = grid.cols() - 1;
    // If col is over bound, goto start of col
    else if (x == grid.cols())
        x = 0;
    // If row is negative, goto end of row
    if (y == -1)
        y = grid.rows() - 1;
    // If row is out of bounds, goto start of row
    else if (y == grid.rows())
        y = 0;
    // Return the word with added characters respectively
    return word + grid[x].at(y);
}

/**
    This function takes the dictionary and grid as inputs, searches the grid
    for all possible words and checks to see it is an actual word. If it is,
    print the word.
    @param Dictionary dict: Dictionary that contains all the words sorted
            Grid mat: Matrix with input grid
 */
void findMatches(Dictionary& dict, Grid mat)
{
    // Vector to store all possible words
    std::vector<std::string> possibleWords;
    // Temp variable to store a potential word
    std::string tempWord;
    int answer1;
    // Get the grid matrix
    matrix<char> grid = mat.getMat();
    // Positions to move around

    // Grid Starting points loop
    for (int posX = 0; posX < grid.cols(); posX++)
    {
        for (int posY = 0; posY < grid.rows(); posY++)
        {
            // Loop for directions
            for (int dir = 0; dir < 8; dir++)
            {
                // Reset pos and temp word
                int x = posX, y = posY;
                tempWord = "";
                // Consider the length of the word (Max is size of grid)
                for (int len = 0; len <= grid.rows(); len++)
                {
                    // Consider each direction
                    switch (dir)
                    {
                        case 0:
                            x--;    y--;
                            tempWord = getWord(x, y, grid, tempWord);
                            break;
                        case 1:
                            x--;
                            tempWord = getWord(x, y, grid, tempWord);
                            break;
                        case 2:
                            x--; y++;
                            tempWord = getWord(x, y, grid, tempWord);
                            break;
                        case 3:
                            y--;
                            tempWord = getWord(x, y, grid, tempWord);
                            break;
                        case 4:
                            y++;
                            tempWord = getWord(x, y, grid, tempWord);
                            break;
                        case 5:
                            x++; y--;
                            tempWord = getWord(x, y, grid, tempWord);
                            break;
                        case 6:
                            x++;
                            tempWord = getWord(x, y, grid, tempWord);
                            break;
                        case 7:
                            x++; y++;
                            tempWord = getWord(x, y, grid, tempWord);
                            break;
                        default:
                            std::cout << "Enta 7mar 5ayo!?\n";
                    }

                    // Make sure we select words greater than 5
                    // (considers 2 added characters)
                    if (len > 3) {
                        answer1 = dict.searchWord(tempWord);
                        if (answer1)
                            // Add word
                            possibleWords.push_back(tempWord);
                        /// Debugging only
                        /// std::cout << "Word: " << tempWord << '\n';
                    }
                }
            }
        }
    }
}

/**
    Reads in the grid file from the keyboard, creates and sorts the dictionary,
    then uses findMatch() to find all words
 */
void search()
{
    int choice;
    // User input file name
    std::string fileName;
    std::cout << "Enter the grid file name: ";
    std::cin >> fileName;

    // Create Grid object
    Grid fileGrid(fileName.c_str());
    std::cout << "Created grid...\n";
    // Establish Dictionary
    Dictionary dict;
    std::cout << "Created dictionary...\n";
    // Read the words
    std::cout << "Reading dictionary...\n";
    dict.readDictionary();
    std::cout << "Finished reading...\n";

    std::cout << "Sort method..\n";
    std::cout << "selection = 1...\n";
    std::cout << "heap = 2...\n";
    std::cout << "quick = 3...\n";
    std::cin >> choice;
    // Check to see if it isn't sorted
    if (!dict.isSaved())
    {
        // If it isn't, sort
        std::cout << "Sorting...\n";
        switch (choice)
        {
            case 1:
                dict.selectionSort();
                break;
            case 2:
                dict.heapSort();
                break;
            case 3:
                dict.callqs();
                break;
            default:
                std::cout<< "A7a yla\n";
        }
    }
    std::cout << "Sorted!\n";

    // Find words and print them
    std::cout << "Matching...\n";
    findMatches(dict, fileGrid);
    std::cout << "Finished getting all possible words...\n";
}


/**
    Main function simply calls the search function which conducts all necessary
    operations.
    @return 0
 */
int main()
{
    search();
    return 0;
}