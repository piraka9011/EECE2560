/**
	EECE2560: Proj4a
	main.cpp
	Purpose: The main file has the implemnation of the Board class and opening
    of the sudoku file.
	@author: Anas Abou Allaban & Turki Alrifaie
	@version: 1.0 3/28/17
*/

#include "Board.h"

int main()
{
	ifstream fin;
	// Read the sample grid from the file.
	string fileName = "/home/pineapple/algo_ws/proj4/sudoku1.txt";
    // Open the file
	fin.open(fileName.c_str());
    // Check if opened
	if (!fin)
	{
		cerr << "Cannot open " << fileName << endl;
		exit(1);
	}
    // Create a Board object
	Board b1(squareSize);
	try
	{
		while (fin && fin.peek() != 'Z')
		{
			b1.initialize(fin);
			b1.print();
			b1.printConflicts();
            b1.isSolved();
		}
	}
	catch (indexRangeError &ex)
	{
		cout << ex.what() << endl;
		exit(1);
	}
}

