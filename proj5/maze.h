/**
 *  EECE2560: Proj5a
 *	maze.h
 *	Purpose: This file has the implementation of the maze object that holds the
 *	valid visiting locations and the ability to print and edit them accordingly.
 *	@author: Anas Abou Allaban & Turki Alrifaie
 *	@version: 1.0 4/15/17
 */

#ifndef PROJ5_MAZE_H
#define PROJ5_MAZE_H

#include <iostream>
#include <list>
#include <limits.h>
#include <vector>
#include <stack>
#include <queue>
#include <fstream>

#include <boost/graph/adjacency_list.hpp>

#include "d_matrix.h"
#include "d_except.h"

using namespace std;
using namespace boost;

// Define the properties associated with a node and edge
struct NodeProperties;
struct EdgeProperties;

int const MaxNumNodex = 9999;

// Create an adjacency list to mimic graph
typedef adjacency_list<vecS, vecS, bidirectionalS, NodeProperties,
        EdgeProperties> Graph;

// Define the properties for the edges and nodes
struct NodeProperties
{
    pair<int, int> cell;
    Graph::vertex_descriptor prev_node;
    int weight;
    bool isVisited;
    bool marked;
};

struct EdgeProperties
{
    int weight;
    bool isVisited;
    bool marked;
};

class maze
{
public:
    maze(ifstream &fin);
    void print(int,int,int,int);
    void printPath(Graph::vertex_descriptor, stack<Graph::vertex_descriptor>,
                   Graph);
    bool isLegal(int i, int j);
    void mapMazeToGraph(Graph &g);
    void setMap(int, int, Graph::vertex_descriptor);
    Graph::vertex_descriptor getMap(int, int) const;
    int getRows(){ return rows; };
    int getCols(){ return cols; };

private:
    int rows; // number of rows in the maze
    int cols; // number of columns in the maze

    matrix<bool> value;
    // Mapping from maze (i,j) values to node index values
    matrix<Graph::vertex_descriptor> map;
};

maze::maze(ifstream &fin)
// Initializes a maze by reading values from fin.  Assumes that the
// number of rows and columns indicated in the file are correct.
{
    fin >> rows;
    fin >> cols;

    char x;

    value.resize(rows,cols);
    for (int i = 0; i <= rows-1; i++)
        for (int j = 0; j <= cols-1; j++)
        {
            fin >> x;
            if (x == 'O')
                value[i][j] = true;
            else
                value[i][j] = false;
        }
    map.resize(rows,cols);
}

void maze::setMap(int i, int j, Graph::vertex_descriptor n)
// Set mapping from maze cell (i,j) to graph node n.
{
    map[i][j] = n;
}

Graph::vertex_descriptor maze::getMap(int i, int j) const
// Return mapping of maze cell (i,j) in the graph.
{
    return map[i][j];
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

    for (int i = 0; i <= rows-1; i++)
    {
        for (int j = 0; j <= cols-1; j++)
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
// Return the value stored at the (i,j) entry in the maze.
{
    if (i < 0 || i > rows || j < 0 || j > cols)
        throw rangeError("Bad value in maze::isLegal");

    return value[i][j];
}

void maze::mapMazeToGraph(Graph &g)
// Create a graph g that represents the legal moves in the maze m.
{
    // First add all the nodes to the graph
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // Check if its a valid position for a node
            if (isLegal(i, j))
            {
                // Create a new node
                Graph::vertex_descriptor newNode = add_vertex(g);
                // Map node in map
                setMap(i, j, newNode);
                // Set properties
                g[newNode].cell = pair<int, int>(i, j);
                g[newNode].prev_node = 1;
                // Check if theres a node in the previous row/col and that we
                // are not at the edge. If so, create an edge between the nodes
                if (i != 0 && value[i-1][j])
                {
                    add_edge(getMap(i - 1, j), newNode, g);
                    add_edge(newNode, getMap(i-1, j), g);
                }
                if (j != 0 && value[i][j-1]) {
                    add_edge(getMap(i, j - 1), newNode, g);
                    add_edge(newNode, getMap(i, j-1), g);
                }
            }
        }
    }
}

void maze::printPath(Graph::vertex_descriptor endNode,
                     stack<Graph::vertex_descriptor> path,
                     Graph g)
// Print the map dynamically and show the directions.
{
    // Crate node vars
    Graph::vertex_descriptor currNode = path.top();
    Graph::vertex_descriptor prevNode = currNode;
    while(!path.empty())
    {
        prevNode = currNode;
        currNode = path.top();

        // Print the current maze
        print(g[endNode].cell.first, g[endNode].cell.second,
              g[currNode].cell.first, g[currNode].cell.second);

        // Print out which direction we need to travel accordingly
        if (g[prevNode].cell.first == g[currNode].cell.first - 1)
            cout << "Go down\n";
        else if (g[prevNode].cell.second == g[currNode].cell.second - 1)
            cout << "Go right\n";
        else if (g[prevNode].cell.first == g[currNode].cell.first + 1)
            cout << "Go up\n";
        else if (g[prevNode].cell.second == g[currNode].cell.second + 1)
            cout << "Go left\n";

        // Remove current node
        path.pop();

        // usleep: microseconds -> ms = x1000
        // Sleep for 750 ms then clear console
        usleep(750000);
        write(1,"\E[H\E[2J",7);
    }
}

#endif //PROJ5_MAZE_H
