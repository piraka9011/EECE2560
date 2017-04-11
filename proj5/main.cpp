/**
	Ali El-Gabri
	main.cpp
*/
#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <queue>
#include <boost/graph/adjacency_list.hpp>
#include "maze.h"

using namespace std;

/**
	Function marks all the nodes in the graph as "unvisited"
	essentially resetting the entire graph
	@param: Graph g
*/
void clearVisited(Graph &g)
{
	pair<Graph::vertex_iterator, Graph::vertex_iterator> vertxRange = vertices(g);
	for (Graph::vertex_iterator vertxIter = vertxRange.first;
		 vertxIter != vertxRange.second; ++vertxIter)
	{
		g[*vertxIter].visited = false;
	}
}

/**
	Set all node weights to passed weight

	@param: Graph g, int weight
*/
void setNodeWeights(Graph &g, int w)
{
	pair<Graph::vertex_iterator, Graph::vertex_iterator> vertxRange = vertices(g);
	for (Graph::vertex_iterator vertxIter = vertxRange.first;
		 vertxIter != vertxRange.second; ++vertxIter)
	{
		g[*vertxIter].weight = w;
	}
}

/**
	Function clears all marked nodes

	@param: graph
*/
void clearMarked(Graph &g)
{
	pair<Graph::vertex_iterator, Graph::vertex_iterator> vertxRange = vertices(g);
	for (Graph::vertex_iterator vertxIter = vertxRange.first;
		 vertxIter != vertxRange.second; ++vertxIter)
	{
		g[*vertxIter].marked = false;
	}
}

/**
	Output operator for the Graph class. Prints out all nodes and their
	properties, and all edges and their properties.
*/
ostream &operator<<(ostream &ostr, const Graph &g)
{
	int edgNum = 0, vertxNum = 0;
	pair<Graph::edge_iterator, Graph::edge_iterator> edgRange = edges(g);
	for (Graph::edge_iterator edgIter = edgRange.first;
	edgIter != edgRange.second; ++edgIter)
	{
		edgNum++;
		ostr << "Edge: " << *edgIter << endl;
		ostr << "Origin Vertex: " << source(*edgIter, g) << endl;
		ostr << "Target Vertex: " << target(*edgIter, g) << endl;
		ostr << "Weight: " << g[*edgIter].weight << endl;
		ostr << "Visited: " << g[*edgIter].visited << endl;
		ostr << "Marked: " << g[*edgIter].marked << endl << endl;
	}
	pair<Graph::vertex_iterator, Graph::vertex_iterator> vertxRange = vertices(g);
	for (Graph::vertex_iterator vertxIter = vertxRange.first;
	vertxIter != vertxRange.second; ++vertxIter)
	{
		ostr << "Vertex: " << *vertxIter << endl;
		ostr << "Cell: (" << g[*vertxIter].cell.first << ", " <<
			g[*vertxIter].cell.second << ")" << endl;
		ostr << "Predecesor: " << g[*vertxIter].pred << endl;
		ostr << "Weight: " << g[*vertxIter].weight << endl;
		ostr << "Visited: " << g[*vertxIter].visited << endl;
		ostr << "Marked: " << g[*vertxIter].marked << endl << endl;
	}
	return ostr;
}


int main()
{
	try
	{
		ifstream fin;

		// Read the maze from the file.
		string fileName = "/home/pineapple/algo_ws/proj5/maze1.txt";

		fin.open(fileName.c_str());
		if (!fin)
		{
			cerr << "Cannot open " << fileName << endl;
			exit(1);
		}

		maze m(fin);
		fin.close();
		m.print(m.numRows() - 1, m.numCols() - 1, 0, 0);

		Graph g;
		m.mapMazeToGraph(g);
		clearVisited(g);
		clearMarked(g);
		setNodeWeights(g, 1);

		Graph::vertex_descriptor start = m.vertxGet(0, 0);
		Graph::vertex_descriptor end = m.vertxGet(m.numRows() - 1, m.numCols() - 1);

		stack<Graph::vertex_descriptor> p1, p2, p3, p4;

		bool solnRecur = m.findPathDFSRecursive(g, start, end, p1);
		cout << "DFS Recursive, Path Size: " << p1.size() << endl;

		bool solnStack = m.findPathDFSNonRecursive(g, start, end, p2);
		cout << "DFS Stack, Path Size: " << p2.size() << endl;

		if (solnRecur || solnStack)
		{
			cout << "Solution found, printing path . . ." << endl;
			sleep(3000);
			m.printPath(end, p4, g);
		}
		else
			cout << "No path exists" << endl;
	}
	catch (baseException & be)
	{
		cout << be.what() << endl;
		exit(1);
	}

    exit(1);
}