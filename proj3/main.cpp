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
    @param: int x: Position x in the grid
            int y: Position y in the grid
            matrix<char> grid: The grid that contains the char matrix
            string word: Our temp word
    @return:string word: Our temp word with an added character according to position
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
    @param: Dictionary dict: dictionary that contains all the
            int suit: suit of the card
    @return:
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

void search()
{
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
    // Check to see if it isn't sorted
    if (!dict.isSaved())
    {
        // If it isn't, sort
        std::cout << "Sorting...\n";
        dict.selectionSort();
    }
    std::cout << "Sorted!\n";

    // Find words and print them
    std::cout << "Matching...\n";
    findMatches(dict, fileGrid);
    std::cout << "Finished getting all possible words...\n";
}

int main()
{
    search();
    return 0;
}


/*
 * // Move in all 8 directions
            for(int direction = 0; direction < 8 ; direction++)
            {
                rowD = posX + x[direction];
                colD = posY + y[direction];

                while (rowD != posX || colD != posY)
                {

                    //Wrap logic:
                    // column wraps
                    if (colD == grid.cols())
                        colD = 0;
                    if (colD == -1)
                        colD = grid.cols() - 1;
                    // row wraps
                    if (rowD == grid.rows())
                        rowD = 0;
                    if (rowD == -1)
                        rowD = grid.rows() - 1;

                    // Turki: I don't know how to explain this? XD
                    tempWord = tempWord + grid[rowD].at(colD);
                    rowD =+ x[direction], colD = y[direction];
                }
                possibleWords.push_back(tempWord);
            }

 / Wrap for rows, where if negative, goto end of row
                    if (rowD < 0)
                        rowD = grid.rows() - 1;
                    // If row is at end, goto start of row
                    else if (rowD >= grid.rows())
                        rowD = 0;

                    // If col is negative, goto end of col
                    if (colD < 0)
                        colD = grid.cols() - 1;
                    // If col is at end goto start of col
                    else if (colD >= grid.cols())
                        colD = 0;

                    // Check if we reached initial letter
                    if (rowD == posY || colD == posX)
                        break;
 */