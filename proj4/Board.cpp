/**
	EECE2560: Proj4a
	Board.cpp
	Purpose: The Board source file has all the functions to initialize the
    board, update conflicts, add a value, clear a value, print the board,
    and check to see if the board is solved.
	@author: Anas Abou Allaban & Turki Alrifaie
	@version: 1.0 3/28/17
*/

#include "Board.h"

/**
 * Return the square number of cell i,j (counting from left to right,
 * top to bottom.  Note that i and j each go from 1 to boardSize
 * @param i: the column index
 *        j: the row index
 * @return the square number of cells i, j from left to right
 */
int squareNumber(int i, int j)
{
	// Note that (int) i/squareSize and (int) j/squareSize are the x-y
	// coordinates of the square that i,j is in.
	return squareSize * ((i - 1) / squareSize) + (j - 1) / squareSize + 1;
}

// Overloaded output operator for vector class.
ostream &operator<< (ostream &ostr, vector<int> &v) {
	for (int i = 0; i < (int)v.size(); i++)
		ostr << v[i] << " ";
	ostr << endl;
	return ostr;
}

/**
 * Initialize the board and set the sizes of the conflict matrices
 */
Board::Board(int squareSize)
	: value(boardSize + 1, boardSize + 1),
	rowConf(boardSize + 1, boardSize + 1),
	colConf(boardSize + 1, boardSize + 1),
	sqrConf(boardSize + 1, boardSize + 1)
{}

/**
 * Reads a Sudoku board from the input file.
 */
void Board::initialize(ifstream &fin)
{
    // Temp char variable
    char ch;
    // Clear our current Board
    clear();

    // Read in all chars
    for (int i = 1; i <= boardSize; i++)
        for (int j = 1; j <= boardSize; j++)
        {
            fin >> ch;
            // If the read char is not Blank
            if (ch != '.')
                // Convert char to int
                setCell(i, j, ch - '0');
            else
                // Otherwise set it to a blank
                setCell(i, j, blank);
        }
}

/**
 * Clear the entire board using the clearCell() f-n
 */
void Board::clear()
{
	for (int i = 1; i <= boardSize; i++)
		for (int j = 1; j <= boardSize; j++)
			clearCell(i, j);
}

/**
 * Clears the cells i and j and updates any conflicts as necessary
 *
 * @param: i: The row index
 *         j: The column index
 */
void Board::clearCell(int i, int j)
{
    // Check if the index are within bounds
    if ( (i < 1 || i > boardSize) || (j < 1 || j > boardSize ))
        throw rangeError("clearCell error: indexes out of bound");

    // Set the current value in the box to a temporary
    int tempVal = value[i][j];
    // Check to see if its a number
    if ((tempVal != 0) && (tempVal != -1))
    {
        // Set as blank and remove any conflicts
        value[i][j] = -1;
        rmvConflict(i, j, tempVal);
    }
}

/**
 * Sets cells i and j to the passed value and updates any conflicts
 *
 * @param: i: The row index
 *         j: The column index
 *         val: The value to be updated
 */
void  Board::setCell(int i, int j, valueType val)
{
    // Check if the index are within bounds
    if (((i < 1) || (i > boardSize)) || ((j < 1) || (j > boardSize)))
		throw rangeError("Error in setCell function: indexes out of range");

    // Set the value to the predefined index
	value[i][j] = val;
    // Check if there's a conflict
	if (val != blank)
		addConflict(i, j, val);
}

/**
	Returns the value stored in cel[i[[j]

	@param: row i col j
	@return: valueType value
*/
valueType Board::getCell(int i, int j)

{
    if (i >= 1 && i <= boardSize && j >= 1 && j <= boardSize)
        return value[i][j];
    else
        throw rangeError("bad value in getCell");
}

/**
 * Updated any conflicts found in the board
 *
 * @param: i: The row index
 *         j: The column index
 *         valuetype val: The value to be updated
 */
void Board::addConflict(int i, int j, valueType val)
{
    // Check if the index are within bounds
    if (i < 1 || i > boardSize || j < 1 || j > boardSize || val < minValue
		|| val > maxValue)
		throw rangeError("addConflict error: indexes out of bound");

    // Get the square number of the cells and update the conflicts
	int sqrnum = squareNumber(i, j);
	colConf[i][j] = true;
    rowConf[i][j] = true;
    sqrConf[sqrnum][j] = true;
}

/**
 * Removes any conflict for cells not creating it
 * @param: i: row index
 *         j: col index
 *         val: value to be updated
 */
void Board::rmvConflict(int i, int j, valueType val)
{
    // Check if the index are within bounds
    if ((i < 1 || i > boardSize) || (j < 1 || j > boardSize) ||
		(val < minValue || val > maxValue))
		throw rangeError("rmvConflict: Error, out of bounds");

    // Get the square number of the cells and update the conflicts
	int sqrnum = squareNumber(i, j);
	colConf[i][val] = false;
    rowConf[i][val] = false;
    sqrConf[sqrnum][val] = false;
}

/**
 * Determines if cells i and j are blank
 * @param: i: row index
 *         j: col index
 * @return: bool: true if blank, false if full
*/
bool Board::isBlank(int i, int j)
{
    // Check if the index are within bounds
	if (i < 1 || i > boardSize || j < 1 || j > boardSize)
		throw rangeError("bad value in setCell");

    // Check if blank
	if (value[i][j] == -1)
		return true;
	else
		return false;
}

/**
 * Returns true if the value will cause a conflict
 * @param: i: row index
 *         j: col index
 *         val: value to update
 * @return: boolean: true or false for conflict
*/
bool Board::isConflict(int i, int j, valueType val)
{
    // Check if the index are within bounds
    if (i < 1 || i > boardSize || j < 1 || j > boardSize ||
		val < minValue || val > maxValue)
		throw rangeError("Error: isConflict - out of index parameters");

    // Get square of cell
	int sqr = squareNumber(i, j);
    // Check if there's any conflict
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
bool Board::isSolved()
{
    // Loop through all conflict matrices and check if they are true
	for (int i = 1; i <= boardSize; i++)
		for (int j = 1; j <= boardSize; j++)
			if (!(rowConf[i][j] && colConf[i][j] && sqrConf[i][j]))
            {
                cout << "Board is not solved yet!" << endl;
                return false;
            }

    cout << "Board has been solved!" << endl;
    return true;
}

/**
 * Prints all the different kinds of conflicts (row, cell, and sqr)
 */
void Board::printConflicts()
{
    cout << "Printing Row Conflicts . . ." << endl;
    cout << "Row Conflict: ";
    for (int row = 1; row <= boardSize; row++) {
        cout << endl << "Row " << row << ": ";
        for (int val = 1; val <= boardSize; val++) {
            cout << rowConf[row][val] << " ";
        }
    }

    cout << endl;

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

/**
 * Prints the current board.
 */
void Board::print()
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
