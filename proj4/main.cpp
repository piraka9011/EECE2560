

#include "Board.h"

int main()
{
	ifstream fin;

	// Read the sample grid from the file.
	string fileName = "/home/osboxes/algo_ws/proj4/sudoku1.txt";

	fin.open(fileName.c_str());
	if (!fin)
	{
		cerr << "Cannot open " << fileName << endl;
		exit(1);
	}
	board b1(squareSize);
	try
	{
		while (fin && fin.peek() != 'Z')
		{
			b1.initialize(fin);
			cout << "hello" << endl;
			b1.print();
			b1.printConflicts();
		}
	}
	catch (indexRangeError &ex)
	{
		cout << ex.what() << endl;
		exit(1);
	}
}

