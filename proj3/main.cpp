#include <iostream>

#include "Dictionary.h"
#include "Grid.h"

void findMatches(Dictionary dict, Grid mat)
{
    std::vector<std::string> possibleWords;
    std::string tempWord;
    matrix<char> grid = mat.getMat();
    // Grid Starting points loop
    for (int posX = 0; posX < grid.rows(); posX++)
    {
        for (int posY = 0; posY < grid.cols(); posY++)
        {
            // Start traversing for words around starting points
            for (int i = 2; i < grid.rows(); i++)
            {
                for (int j = 2; j < grid.cols(); j++)
                {
                    tempWord = tempWord + grid[posX].at(posY) +
                               grid[posX + 1].at(posY + 1);
                }

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