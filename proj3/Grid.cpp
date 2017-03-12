//
// Created by piraka9011 on 3/1/17.
//

#include "Grid.h"

Grid::Grid(std::string matrixFile)
{
    // Add directory to file
    // Ubuntu path /home/piraka9011/Desktop/algo_ws/proj3/
    std::string fileName = "/home/piraka9011/Desktop/algo_ws/proj3/" + matrixFile;
    // Open file
    std::ifstream inFile (fileName.c_str());

    // Check if file is open
    if (inFile.is_open())
    {
        // Read in # of rows/cols from file header
        int row, col;
        inFile >> row >> col;

        // Resize matrix accordingly
        charMat.resize(row, col);

        /// DEBUGGING
        std::cout << "row: " << row << " col: " << col;
        // Loop through rows and cols, store data in char matrix
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                inFile >> charMat[i].at(j);
                /// DEBUGGING
                ///std::cout << charMat[i].at(j);
            }
            /// DEBUGGING
            ///std::cout << '\n';
        }
    }
    else
        // Uh-oh
        std::cout << "ERROR: UNABLE TO OPEN MATRIX FILE\n";
}
