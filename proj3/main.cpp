#include "Dictionary.h"
#include "Grid.h"

void checkBounds(int& x, int& y, matrix<char> grid) {
    if (x == -1)
        x = grid.cols() - 1;
    else if (x == grid.cols())
        x = 0;
    if (y == -1)
        y = grid.rows() - 1;
    else if (y == grid.rows())
        y = 0;
}

void findMatches(Dictionary dict, Grid mat)
{
    // Vector to store all possible words
    std::vector<std::string> possibleWords;
    // Temp variable to store a potential word
    std::string tempWord;
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
                int x = posX, y = posY;
                tempWord = "";
                for (int len = 0; len < grid.rows(); len++)
                {
                    // Consider each direction
                    switch (dir)
                    {
                        case 0:
                            x--;    y--;
                            checkBounds(x, y, grid);
                            tempWord = grid[x].at(y) + tempWord;
                            break;
                        case 1:
                            x--;
                            checkBounds(x, y, grid);
                            tempWord = grid[x].at(y) + tempWord;
                            break;
                        case 2:
                            x--; y++;
                            checkBounds(x, y, grid);
                            tempWord = grid[x].at(y) + tempWord;
                            break;
                        case 3:
                            y--;
                            checkBounds(x, y, grid);
                            tempWord = grid[x].at(y) + tempWord;
                            break;
                        case 4:
                            y++;
                            checkBounds(x, y, grid);
                            tempWord = grid[x].at(y) + tempWord;
                            break;
                        case 5:
                            x++; y--;
                            checkBounds(x, y, grid);
                            tempWord = grid[x].at(y) + tempWord;
                            break;
                        case 6:
                            x++;
                            checkBounds(x, y, grid);
                            tempWord = grid[x].at(y) + tempWord;
                            break;
                        case 7:
                            x++; y++;
                            checkBounds(x, y, grid);
                            tempWord = grid[x].at(y) + tempWord;
                            break;
                    }
                    if (x == posX  || y == posY)
                        break;
                    if (len > 5)
                        // Add word
                        possibleWords.push_back(tempWord);
                }

            }
        }
    }

    std::cout << "Finished getting all possible words...\n";
    // Loop through all possible words and see if it matches a word in the dict
    std::string notFound = "Word not found";
    std::string answer;
    for (int i = 0; i < possibleWords.size(); i++)
    {
        std::cout << "Word: " << possibleWords.at(i) << '\n';
        answer = dict.searchWord(possibleWords.at(i));
        // compare() RETURNS 0 IF TRUE!!!!!
        // If the word is found, its a match
        if (answer.compare(notFound))
            std::cout << "Found a match! the word is: " << answer << '\n';
        // Otherwise remove it from list of possible words
        else
            possibleWords.erase(possibleWords.begin() + i);
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