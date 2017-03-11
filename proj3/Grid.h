//
// Created by piraka9011 on 3/1/17.
//

#ifndef PROJ3_GRID_H
#define PROJ3_GRID_H

#include "d_matrix.h"

#include <fstream>
#include <sstream>

class Grid {
private:
    matrix<char> charMat;

public:
    Grid(std::string matrixFile);
    matrix<char> getMat() { return charMat; };

};


#endif //PROJ3_GRID_H
