/**
	EECE2560: Proj3a
	Grid.cpp
	Purpose: This file provides the implementation for the Grid class. Its only
    implementation is that of the constructor as that is all that is needed.
	@author: Anas Abou Allaban & Turki Alrifaie
	@version: 1.0 3/13/17
*/

#include "Grid.h"

/**
    The Grid constructor opens the grid file, reads in the rows/cols, resizes
    the grid accordingly and then stores each character into the grid
    @param  string matrixFile: The name of the file to be opened
                                **** NOTE TO TA ****
    Please note that this program was tested on Ubuntu 14.04. Other students
    reported errors with opening the file the way we do. Please make sure that
    you put in the correct file path extension.
    If the file is in the same directory as the project, you may not need to
    add the file path extension.
    ***************************************************************************
 */
Grid::Grid(std::string matrixFile)
{
    // Add directory to file

    /// CHANGE DIRECTORY HERE   /////////////////////////////////////////
    std::string fileName = "/home/pineapple/algo_ws/proj3/" + matrixFile;
    /////////////////////////////////////////////////////////////////////

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

        // Loop through rows and cols, store data in char matrix
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
                inFile >> charMat[i].at(j);
        }
    }
    else
        // Uh-oh
        std::cout << "ERROR: UNABLE TO OPEN MATRIX FILE\n";
}
