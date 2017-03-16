/**
	EECE2560: Proj3a
	Grid.h
	Purpose: The Grid header file contains all the function definitions for the
    grid. Here, we only require a constructor and a getter to get the matrix.
	@author: Anas Abou Allaban & Turki Alrifaie
	@version: 1.0 3/13/17
*/

#ifndef PROJ3_GRID_H
#define PROJ3_GRID_H

#include "d_matrix.h"

#include <fstream>  //std::ifstream

class Grid {
private:
    //Matrix with letters
    matrix<char> charMat;

public:
    Grid(std::string matrixFile);
    matrix<char> getMat() { return charMat; }

};

#endif //PROJ3_GRID_H
