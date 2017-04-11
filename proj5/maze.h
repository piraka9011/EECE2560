/**
	Ali El-Gabri
	maze.h
*/

#pragma once

#ifndef MAZE_H
#define MAZE_H

#include <boost/graph/adjacency_list.hpp>
#include <iostream>
#include <limits.h>
#include <list>
#include <fstream>
#include <queue>
#include <vector>
#include <stack>
#include "d_except.h"
#include "d_matrix.h"

using namespace boost;
using namespace std;

struct VertexProperties;
struct EdgeProperties;

typedef adjacency_list<vecS, vecS, bidirectionalS, VertexProperties, EdgeProperties> Graph;

struct VertexProperties
{
    pair<int, int> cell; // maze cell (x,y) value
    Graph::vertex_descriptor pred; // predecessor node
    int weight;
    bool visited;
    bool marked;
};

// Create a struct to hold properties for each edge
struct EdgeProperties
{
    int weight;
    bool visited;
    bool marked;
};

#define LargeValue 99999999


class maze
{
public:
    maze(ifstream &fin);
    void print(int, int, int, int);
    bool isLegal(int i, int j);
    void mapMazeToGraph(Graph &g);
    void printPath(Graph::vertex_descriptor end,
                   stack<Graph::vertex_descriptor> &s,
                   Graph g);
    int numRows() { return rows; };
    int numCols() { return cols; };

private:
    int rows; // number of rows in the maze
    int cols; // number of columns in the maze12 a
    matrix<bool> value;
    matrix<Graph::vertex_descriptor> vertices;
};
#endif 