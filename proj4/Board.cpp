#include "Board.h"


int squareNumber(int i, int j)
// Return the square number of cell i,j (counting from left to right,
// top to bottom.  Note that i and j each go from 1 to boardSize
{
	// Note that (int) i/squareSize and (int) j/squareSize are the x-y
	// coordinates of the square that i,j is in.  

	return squareSize * ((i - 1) / squareSize) + (j - 1) / squareSize + 1;
}

//Overloaded output operator for vector class.
ostream &operator<<(ostream &ostr, vector<int> &v) {
	for (int i = 0; i < (int)v.size(); i++)
		ostr << v[i] << " ";
	ostr << endl;
	return ostr;
}


board::board(int squareSize)
	: value(boardSize + 1, boardSize + 1),
	rowConf(boardSize + 1, boardSize + 1),
	colConf(boardSize + 1, boardSize + 1),
	sqrConf(boardSize + 1, boardSize + 1) {}

void board::clear()
// clear the entire board.
{
	for (int i = 1; i <= boardSize; i++)
		for (int j = 1; j <= boardSize; j++)
			clearCell(i, j);
}

/**
	Sets cells i and j to the passed value and updates any conflicts
	
	@param: row, col, value
	@return:
*/
void  board::setCell(int i, int j, valueType val)
{
	if (((i < 1) || (i > boardSize)) || ((j < 1) || (j > boardSize)))
	{
		throw rangeError("Error in setCell function: indexes out of range");
	}
	value[i][j] = val;
	if (val != blank) 						//!< If not blank, conflict!
		addConflict(i, j, val);
}
/**
	Updated any conflicts found in the board

	@param:
		int, int, valuetype (row column and value)
	@return:
*/
void board::addConflict(int i, int j, valueType val)
{
	if (i < 1 || i > boardSize || j < 1 || j > boardSize || val < minValue
		|| val > maxValue)
		throw rangeError("addConflict error: indexes out of bound");

	int sqrnum = squareNumber(i, j);

	colConf[i][j] = true; rowConf[i][j] = true; sqrConf[sqrnum][j] = true;
}
/**
	Clears the cells i and j and updates any conflicts as necessary
	
	@param: row col
	@return:
*/
void board::clearCell(int i, int j)
{
	if ( (i < 1 || i > boardSize) || (j < 1 || j > boardSize ))
		throw rangeError("clearCell error: indexes out of bound");

	int tempVal = value[i][j];							//!< Assigns value to temp val
	if ((tempVal != 0) && (tempVal != -1))
	{
		value[i][j] = -1;
		rmvConflict(i, j, tempVal);
	}
}
/**
	Removes any conflict for cells not creating it
	
	@param: row, col, value
	@return:
*/
void board::rmvConflict(int i, int j, valueType val)
{
	if ((i < 1 || i > boardSize) || (j < 1 || j > boardSize) ||
		(val < minValue || val > maxValue))
	{
		throw rangeError("rmvConflict: Error, out of bounds");
	}
	int sqrnum = squareNumber(i, j);
	colConf[i][val] = false; rowConf[i][val] = false; sqrConf[sqrnum][val] = false;		
}
/**
	Prints all the different kinds of conflicts (row, cell, and sqr)
	
	@param:
	@return:
*/
void board::printConflicts()
{
	cout << "Printing Row Conflicts . . ." << endl;
	cout << "Row Conflict: ";
	for (int row = 1; row <= boardSize; row++) {
		cout << endl << "Row " << row << ": ";
		for (int val = 1; val <= boardSize; val++) {
			cout << rowConf[row][val] << " ";
		}
	}

	cout << "Printing Column Conflicts . . ." << endl;
	cout << "Column Conflict: ";
	for (int col = 1; col <= boardSize; col++) {
		cout << endl << "Column " << col << ": ";
		for (int val = 1; val <= boardSize; val++) {
			cout << colConf[col][val] << " ";
		}
	}

	cout << endl;

	cout << "Printing 'Square' Conflicts . . ." << endl;
	cout << "Square Conflict: ";
	for (int sqr = 1; sqr <= boardSize; sqr++) {
		cout << endl << "Square " << sqr << ": ";
		for (int val = 1; val <= boardSize; val++) {
			cout << sqrConf[sqr][val] << " ";
		}
	}
	cout << endl;
}
void board::initialize(ifstream &fin)
// Read a Sudoku board from the input file.
{
	char ch;

	clear();

	for (int i = 1; i <= boardSize; i++)
		for (int j = 1; j <= boardSize; j++)
		{
			fin >> ch;

			// If the read char is not Blank
			if (ch != '.')
				setCell(i, j, ch - '0');   // Convert char to int
			else
				setCell(i, j, blank);
		}
}

/**
	Functiosn determines if cells i and j are blank
	
	@param: row i and col j
	@return: bool (true if blank, false if full)
*/
bool board::isBlank(int i, int j)
{
	if (i < 1 || i > boardSize || j < 1 || j > boardSize)
		throw rangeError("bad value in setCell");

	if (value[i][j] == -1)
		return true;
	else
		return false;
}

/**
	Returns true if the value will cause a conflict
	
	@param: row i, col j, and "value" val
	@return: boolean true or false for conflict
*/
bool board::isConflict(int i, int j, valueType val)
{
	if (i < 1 || i > boardSize || j < 1 || j > boardSize ||
		val < minValue || val > maxValue)
	{
		throw rangeError("Error: isConflict - out of index parameters");
	}

	int sqr = squareNumber(i, j);
	
	if (colConf[i][val] || rowConf[i][val] || sqrConf[sqr][val])
		return true;
	else
		return false;
}
/**
	Determines if the board is solved
	
	@param:
	@return: bool true false
*/
bool board::isSolved()
{
	for (int i = 1; i <= boardSize; i++)
		for (int j = 1; j <= boardSize; j++)
			if (!(rowConf[i][j] && colConf[i][j] && sqrConf[i][j]))
				return false;

return true;
}
/**
	Returns the value stored in cel[i[[j]
	
	@param: row i col j
	@return: valueType value
*/
valueType board::getCell(int i, int j)

{
	if (i >= 1 && i <= boardSize && j >= 1 && j <= boardSize)
		return value[i][j];
	else
		throw rangeError("bad value in getCell");
}

void board::print()
// Prints the current board.
{
	for (int i = 1; i <= boardSize; i++)
	{
		if ((i - 1) % squareSize == 0)
		{
			cout << " -";
			for (int j = 1; j <= boardSize; j++)
				cout << "---";
			cout << "-";
			cout << endl;
		}
		for (int j = 1; j <= boardSize; j++)
		{
			if ((j - 1) % squareSize == 0)
				cout << "|";
			if (!isBlank(i, j))
				cout << " " << getCell(i, j) << " ";
			else
				cout << "   ";
		}
		cout << "|";
		cout << endl;
	}

	cout << " -";
	for (int j = 1; j <= boardSize; j++)
		cout << "---";
	cout << "-";
	cout << endl;
}
