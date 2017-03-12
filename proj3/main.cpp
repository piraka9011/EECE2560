#include "Dictionary.h"
#include "Grid.h"

void findMatches(Dictionary dict, Grid mat)
{
    // Vector to store all possible words
    std::vector<std::string> possibleWords;
    // Temp variable to store a potential word
    std::string tempWord;
    // Get the grid matrix
    matrix<char> grid = mat.getMat();
    // Positions to move around
    int x[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int y[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    int rowD, colD;
    // Grid Starting points loop
    for (int posX = 0; posX < grid.rows(); posX++)
    {
        for (int posY = 0; posY < grid.cols(); posY++)
        {
            // Inits the first letter to search around
            tempWord = grid[posX].at(posY);

            // Move in all 8 directions
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
                        rowD = grid.rows();

                    // Turki: I don't know how to explain this? XD
                    tempWord = tempWord + grid[rowD].at(colD);
                    rowD =+ x[direction], colD = y[direction];
                }
                possibleWords.push_back(tempWord);
            }
        }
    }

    // Loop through all possible words and see if it matches a word in the dict
    std::string notFound = "Word not found";
    std::string answer;
    for (int i = 0; i < possibleWords.size(); i++)
    {
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

    // Find words and print them
    findMatches(dict, fileGrid);
}

int main()
{
    search();
    return 0;
}