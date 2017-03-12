#include <iostream>

#include "Dictionary.h"
#include "Grid.h"

void findMatches(Dictionary dict, Grid mat)
{
    std::vector<std::string> possibleWords;
    std::string tempWord;
    matrix<char> grid = mat.getMat();
    int x[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int y[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    // Grid Starting points loop
    for (int posX = 0; posX < grid.rows(); posX++)
    {
        for (int posY = 0; posY < grid.cols(); posY++)
        {
            //Intis the first letter to search around
            tempWord = grid[posX].at(posY);

            //move in all 8 directions
            for(int direction=0; direction < 8 ; direction++){
                int k, rowD = posX + x[direction], colD = posY + y[direction];

                while (rowD != posX || colD != posY)
                {

                    //Wrap logic:
                    // column wraps
                    if (colD == grid.cols())
                        colD = 0;
                    if (colD ==-1)
                        colD = grid.cols()-1;
                    //row wraps
                    if (rowD == grid.rows())
                        rowD = 0;
                    if (rowD ==-1)
                        rowD = grid.rows();

                    tempWord = tempWord + grid[rowD].at(colD);
                    rowD =+ x[direction], colD= y[direction];
                }
                possibleWords.push_back(tempWord);
            }

            }

        }

    }

void search()
{
    std::string fileName;
    std::cout << "Enter the grid file name: ";
    std::cin >> fileName;

    // Create Grid object
    Grid fileGrid(fileName);

    // Establish Dictionary
    Dictionary dict;
    // Read the words
    dict.readDictionary();
    // Check to see if it isn't sorted
    if (!dict.isSaved())
    {
        // If it isn't, sort
        dict.selectionSort();
    }

    findMatches(dict, fileGrid);
}

int main() {

    return 0;
}