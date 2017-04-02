/**
	EECE2560: Proj4a
	main.cpp
	Purpose: The main file has the implemnation of the Board class and opening
    of the sudoku file.
	@author: Anas Abou Allaban & Turki Alrifaie
	@version: 1.0 3/28/17
*/

#include "Board.h"
/**
	Function determines which row,col to solve next based on which "row,col" has
	the lowest number of possible solutions

	@param: board, row, col
	@return:
*/
void moveOn(Board& board, int& i, int& j)
{
    int numSol;																	//!< num of possible sol
    for (int k = minValue; k <= maxValue; k++) 												//!< Iterate through board looking for one possible solution, and then onward
    {
        for (int r = 1; r <= boardSize; r++) 									//!< Iterates through entirety of board
        {
            for (int c = 1; c <= boardSize; c++)
            {
                if (board.isBlank(r, c)) 										//!< Is row,col blank?
                {
                    numSol = 0;
                    for (valueType val = minValue; val <= maxValue; val++) 		//!< Iterate through each val... if no conflicts, increment numSol
                    {
                        if (!board.isConflict(r, c, val))
                        {
                            numSol++;
                        }
                    }
                    if (numSol <= k)
                    {
                        i = r;
                        j = c;
                        return;
                    }
                }
            }
        }
    }
}
/**
	Recursive function.. solves the board and only stops when board is solved

	@param: board, row, col, number of recursions
	@return: true or false
*/
bool IsSolved(Board& board, int i, int j, int& numIterations) {
    numIterations++; 																//!< Number of iterations
    valueType val = minValue;
    bool isolved = board.isSolved();

    while (!isolved && val <= maxValue) 											//!< Keep calling isSolved while not solved and less than maxval
    {

        if (!board.isConflict(i, j, val)) 										//!< If not conflict, set the cell to that val
        {
            board.setCell(i, j, val);
            int moveonI = i, moveonJ = j;
            moveOn(board, moveonI, moveonJ);
            isolved = IsSolved(board, moveonI, moveonJ, numIterations);				//!< Next Location

            if (!isolved) 															//!< Backtrack as necessary...
            {
                board.clearCell(i, j);
                val++;
            }
        }
        else
        {
            val++;
        }
    }
    return isolved;
}
int main()
{
    // Vars for iterations & board
    int totalItr = 0;
    int numBoards = 0;
	// Read the sample grid from the file.
    ifstream fin;
	string fileName = "/home/osboxes/algo_ws/proj4/sudoku.txt";
    // Open the file
	fin.open(fileName.c_str());
    // Check if opened
	if (!fin)
	{
		cerr << "Cannot open " << fileName << endl;
		exit(1);
	}
    // Create a Board object
	Board b1;
	try
	{
		while (fin && fin.peek() != 'Z')
		{
            // Init board
			b1.initialize(fin);
            // Solve
            b1.moveOn();
            b1.solve();
            // Update vars
            totalItr += b1.getNumIterations();
            numBoards++;
			b1.print();
            cout << "Total number of calls for board " << numBoards << ": "
                 << b1.getNumIterations() << '\n';
		}
        int avgItr = totalItr / numBoards;
        cout << "Average number of calls over " << numBoards << " boards: "
             << avgItr << '\n';
	}
	catch (indexRangeError &ex)
	{
		cout << ex.what() << endl;
		exit(1);
	}
}

/*
 * try
	{
		while (fin && fin.peek() != 'Z')
		{
			int i, j, numIterations = 0;
			b1.initialize(fin);
			moveOn(b1, i, j);
			IsSolved(b1, i, j, numIterations);
			totIter += numIterations;
			numbrd++;
			b1.print();
			cout << "Total number of calls for this board: " << numIterations <<  endl;
		}
		int avgIter = totIter / numbrd;
		cout << "Running average of isSolved function: " << avgIter << endl;
	}
 */
