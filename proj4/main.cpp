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
    // Num of possible sol
    int numSol;
    // Iterate through board looking for one possible solution, and then onward
    for (int k = minValue; k <= maxValue; k++)
    {
        // Iterates through entirety of board
        for (int r = 1; r <= boardSize; r++)
        {
            for (int c = 1; c <= boardSize; c++)
            {
                // Is position blank?
                if (board.isBlank(r, c))
                {
                    numSol = 0;
                    // Iterate through each val... if no conflicts, increment numSol
                    for (valueType val = minValue; val <= maxValue; val++)
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
    // Increment iteration for each call
    numIterations++;
    // Set the minValue;
    valueType val = minValue;
    bool isolved = board.isSolved();
    // Keep calling isSolved while not solved and less than maxval
    while (!isolved && val <= maxValue)
    {
        // If no conflict, set the cell to that val
        if (!board.isConflict(i, j, val))
        {
            board.setCell(i, j, val);
            int moveonI = i, moveonJ = j;
            // Next Location
            moveOn(board, moveonI, moveonJ);
            isolved = IsSolved(board, moveonI, moveonJ, numIterations);

            // Backtrack as necessary...
            if (!isolved)
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
    int row = 1, col = 1;
	// Read the sample grid from the file.
    ifstream fin;
	string fileName = "/home/piraka9011/algo_ws/proj4/sudoku1.txt";
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
            int i, j, numIterations = 0;
            b1.initialize(fin);
            moveOn(b1, i, j);
            IsSolved(b1, i, j, numIterations);
            totalItr += numIterations;
            numBoards++;
            b1.print();
            cout << "Total number of calls for this board: " << numIterations <<  endl;

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

/*
 *             // Init board
			b1.initialize(fin);
            // Solve
            b1.moveOn(row, col);
            b1.solve(row, col);
            // Print results
			b1.print();
            cout << "Total number of calls for board " << numBoards << ": "
                 << b1.getNumIterations() << '\n';
            // Update vars
            totalItr += b1.getNumIterations();
            numBoards++; row = 1; col = 1;
 */