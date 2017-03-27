#pragma once
#include <iostream>
#include <limits.h>
#include "d_matrix.h"
#include "d_except.h"
#include <list>
#include <fstream>

using namespace std;

typedef int valueType; // The type of the value in a cell
const int blank = -1;  // Indicates that a cell is blank

const int squareSize = 3;  //  The number of cells in a small square
						   //  (usually 3).  The board has
						   //  squareSize^2 rows and squareSize^2
						   //  columns.

const int boardSize = squareSize * squareSize;

const int minValue = 1;
const int maxValue = 9;

class board
	// Stores the entire Sudoku board
{
public:
	board(int);
	void clear();
	void initialize(ifstream &fin);
	void print();
	void setCell(int i, int j, valueType val);
	void clearCell(int, int);
	void printConflicts();
	void rmvConflict(int, int, valueType val);
	void addConflict(int, int, valueType val);

	valueType getCell(int i, int j);

	bool isBlank(int, int);
	bool isSolved();
	bool isConflict(int, int, valueType val);
private:

	// The following matrices go from 1 to boardSize in each
	// dimension.  I.e. they are each (boardSize+1) X (boardSize+1)
	matrix<valueType> value;
	matrix<bool> rowConf;				//row conflict
	matrix<bool> colConf;				//col conflict
	matrix<bool> sqrConf;				//square conflict
};