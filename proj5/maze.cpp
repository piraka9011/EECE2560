/**
	Ali El-Gabri
	maze.cpp
*/

#include "maze.h"


maze::maze(ifstream &fin) 
{
	//Initializes a maze by reading values from fin.  Assumes that the
	//number of rows and columns indicated in the file are correct
    fin >> rows;
    fin >> cols;

    char x;

    value.resize(rows, cols);
    for (int i = 0; i <= rows - 1; i++)
        for (int j = 0; j <= cols - 1; j++)
        {
            fin >> x;
            if (x == 'O')
                value[i][j] = true;
            else
                value[i][j] = false;
        }

    vertices.resize(rows, cols);
}

void maze::print(int goalI, int goalJ, int currI, int currJ)
// Print out a maze, with the goal and current cells marked on the
// board.
{
	cout << endl;

	if (goalI < 0 || goalI > rows || goalJ < 0 || goalJ > cols)
		throw rangeError("Bad value in maze::print");

	if (currI < 0 || currI > rows || currJ < 0 || currJ > cols)
		throw rangeError("Bad value in maze::print");

	for (int i = 0; i <= rows - 1; i++)
	{
		for (int j = 0; j <= cols - 1; j++)
		{
			if (i == goalI && j == goalJ)
				cout << "*";
			else
				if (i == currI && j == currJ)
					cout << "+";
				else
					if (value[i][j])
						cout << " ";
					else
						cout << "X";
		}
		cout << endl;
	}
	cout << endl;
}

bool maze::isLegal(int i, int j)
// Return the value stored at the (i,j) entry in the maze, indicating
// whether it is legal to go to cell (i,j).
{
	if (i < 0 || i > rows || j < 0 || j > cols)
		throw rangeError("Bad value in maze::isLegal");

	return value[i][j];
}
/**
Function creates a graph 'g' that symbolizes all the legal moves in the
provided maze 'm'

@param: Graph g
*/
void maze::mapMazeToGraph(Graph &g)
{
	for (int i = 0; i < rows; i++)										//!< Loops around the entire maze
	{
		for (int j = 0; j < cols; j++)
		{
			if (value[i][j])
			{
				Graph::vertex_descriptor v = add_vertex(g);
				vertices[i][j] = v;
				g[v].cell = pair<int, int>(i, j);
				g[v].pred = 1;
				if (i != 0 && value[i - 1][j])
				{
					add_edge(vertices[i - 1][j], v, g);
				}
				if (j != 0 && value[i][j - 1])
				{
					add_edge(vertices[i][j - 1], v, g);
				}
			}
		}
	}
}

/**
Function prints out the path of the maze
*/
void maze::printPath(Graph::vertex_descriptor end,
	stack<Graph::vertex_descriptor> &s,
	Graph g)
{
	Graph::vertex_descriptor vertxCur;

	while (!s.empty())
	{
		vertxCur = s.top();
		s.pop();
		print(g[end].cell.first, g[end].cell.second,
			g[vertxCur].cell.first, g[vertxCur].cell.second);
	}
}