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
	//!< Loops around the entire maze
	for (int i = 0; i < rows; i++)
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

/**
	Function marks all the nodes in the graph as "unvisited"
	essentially resetting the entire graph
	@param: Graph g
*/
void clearVisit(Graph &g)
{
	pair<Graph::vertex_iterator, Graph::vertex_iterator> vertxRange = vertices(g);
	for (Graph::vertex_iterator vertxIter = vertxRange.first;
		 vertxIter != vertxRange.second; ++vertxIter)
	{
		g[*vertxIter].visited = false;
	}
}


/**
	A recursive Depth First Search function
	@param: Graph h, vertex_descriptor (start v), vertex_descriptor (end v),
			vertex_descriptor (the path)
	@return: bool true false
*/
bool maze::findPathDFSRecursive(Graph& g, Graph::vertex_descriptor head,
						  Graph::vertex_descriptor tail, stack<Graph::vertex_descriptor>& path)
{
	clearVisit(g);
	return traverseDFSRecursive(g, head, tail, path);
}

/**
	Depth-First Search method utilizing a stack instead of Recursion

		@param: Graph h, vertex_descriptor (start v), vertex_descriptor (end v),
				vertex_descriptor (the path)
		@return: bool true false
*/
bool maze::findPathDFSNonRecursive(Graph& g, Graph::vertex_descriptor head,
					  Graph::vertex_descriptor tail, stack<Graph::vertex_descriptor>& path)
{
	clearVisit(g);
	bool isLocated = false;
	//!< Start Vertice
	stack<Graph::vertex_descriptor> hVertc;
	hVertc.push(head);
	//!< Current vertx
	Graph::vertex_descriptor vertxCur;

	while (!hVertc.empty() && !isLocated)
	{
		vertxCur = hVertc.top();
		hVertc.pop();
		//!< If the vertex is end and not visited, true
		if (!g[vertxCur].visited)
		{
			if (vertxCur == tail)
			{
				isLocated = true;
			}
			g[vertxCur].visited = true;
			pair<Graph::adjacency_iterator, Graph::adjacency_iterator>
					vertxRange = adjacent_vertices(vertxCur, g);
			//!< Loop through entirety of stack
			for (Graph::adjacency_iterator vertxIter = vertxRange.first;
				 vertxIter != vertxRange.second; ++vertxIter)
			{
				if (!g[*vertxIter].visited)
				{
					g[*vertxIter].pred = vertxCur;
					hVertc.push(*vertxIter);
				}
			}
		}
	}
	if (isLocated)
	{
		while (vertxCur != -1)
		{
			path.push(vertxCur);
			vertxCur = g[vertxCur].pred;
		}
	}
	return isLocated;
}

/**
Function for recursive depth first search. Traverses through graph.

@param: Graph, vertex_descriptor (vertex), vertex_descritor (end),
vertex_descriptor (the path)
@return: boolean
*/
bool maze::traverseDFSRecursive(Graph& g, Graph::vertex_descriptor v,
						  Graph::vertex_descriptor tail, stack<Graph::vertex_descriptor>& path)
{
	//Check if we are at the tail
	// Are we at the end of the v or not?
	if (v == tail)
	{
		path.push(v);
		return true;
	}
	else
	{
		g[v].visited = true;
		bool isLocated = false;
		pair<Graph::adjacency_iterator, Graph::adjacency_iterator>
				vertxRange = adjacent_vertices(v, g);

		for (Graph::adjacency_iterator vertxIter = vertxRange.first;
			 vertxIter != vertxRange.second; ++vertxIter)
		{
			// If visited, recurse
			if (!g[*vertxIter].visited)
			{
				isLocated = traverseDFSRecursive(g, *vertxIter, tail, path);
			}
			if (isLocated) break;
		}
		if (isLocated)
		{
			path.push(v);
		}
		return isLocated;
	}
}
