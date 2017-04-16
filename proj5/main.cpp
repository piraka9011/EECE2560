/**
 *  EECE2560: Proj5a
 *	main.cpp
 *	Purpose: The main file has all the DFS path finding functions and simulates
 *	the traversal of the map.
 *	@author: Anas Abou Allaban & Turki Alrifaie
 *	@version: 1.0 4/15/17
 */

#include "maze.h"

/**
 * Clears the isVisited property of a graph's nodes
 * @param g: A Graph object
 */
void clearVisited(Graph &g)
{
    // Create a pair with all the nodes
    pair<Graph::vertex_iterator, Graph::vertex_iterator> nodeRange = vertices(g);
    // Loop through entire graph
    for (Graph::vertex_iterator currNode = nodeRange.first;
         currNode != nodeRange.second; ++currNode)
        // Set visited property to false
        g[*currNode].isVisited = false;
}

/**
 * Clears the prev_node property of a graph's nodes
 * @param g: A Graph object
 */
void clearPrev(Graph &g)
{
    pair<Graph::vertex_iterator, Graph::vertex_iterator> vertxRange = vertices(g);
    for (Graph::vertex_iterator vertxIter = vertxRange.first;
         vertxIter != vertxRange.second; ++vertxIter) {
        g[*vertxIter].prev_node = -1;
    }
}

/**
 * Clears the marked property of a graph's nodes
 * @param g: A Graph object
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
 * Set the weights of all the nodes for a graph
 * @param g: A Graph object
 * @param w: The weight of the nodes
 */
void setNodeWeights(Graph& g, int w)
{
    pair<Graph::vertex_iterator, Graph::vertex_iterator> vertxRange = vertices(g);
    for (Graph::vertex_iterator vertxIter = vertxRange.first;
         vertxIter != vertxRange.second; ++vertxIter)
    {
        g[*vertxIter].weight = w;
    }
}

void setEdgeWeights(Graph& g, int w)
{
    pair<Graph::edge_iterator, Graph::edge_iterator> edgeRange = edges(g);
    for (Graph::edge_iterator edgeItr = edgeRange.first;
         edgeItr != edgeRange.second; ++edgeItr)
    {
        g[*edgeItr].weight = w;
    }
}

void clearVisitedEdge(Graph& g)
{
    pair<Graph::edge_iterator, Graph::edge_iterator> edgeRange = edges(g);
    for (Graph::edge_iterator edgeItr = edgeRange.first;
         edgeItr != edgeRange.second; ++edgeItr)
    {
        g[*edgeItr].isVisited = false;
    }
}

/**
 * The main recursive implementation of DFS. This function iterates through a
 * graph's adjacent nodes looking for a path. It visits the first adjacent node
 * it finds until it reaches the goal node. If no goal node is found, function
 * returns false
 * @param g: A graph object
 * @param currNode: The current node that is being visited
 * @param goal: The goal node to visit
 * @param path: A stack that contains the path
 * @return true if a path is found, false otherwise
 */
bool DFSRecursive(Graph &g,
                  Graph::vertex_descriptor currNode,
                  Graph::vertex_descriptor goal,
                  stack<Graph::vertex_descriptor>& path)
{
    // If the current node is at the goal, add it to path and return
    if (currNode == goal)
    {
        path.push(currNode);
        return true;
    }
    else
    {
        // Set the current node to visited
        g[currNode].isVisited = true;
        bool isLocated = false;
        // Get the adjacent vertices to the node
        pair<Graph::adjacency_iterator, Graph::adjacency_iterator>
                nodeRange = adjacent_vertices(currNode, g);
        // Check if path exists for each adjacent vertex
        for (Graph::adjacency_iterator nodeItr = nodeRange.first;
             nodeItr != nodeRange.second; ++nodeItr)
        {
            // Check if the node is visited
            if (!g[*nodeItr].isVisited)
                // If not, do DFS
                isLocated = DFSRecursive(g, *nodeItr, goal, path);
            // If a valid path was found add it to stack
            if (isLocated)
            {
                path.push(currNode);
                break;
            }
        }
        return isLocated;
    }
}

/**
 * The initial function that calls the DFSRecursive function. Makes sure that
 * all nodes are set to not visited initially.
 * @param g: A Graph object
 * @param currNode: The current node that is being visited
 * @param goal: The goal node to visit
 * @param path: A stack that contains the path
 * @return true if a path is found, false otherwise
 */
bool findPathRecursive(Graph& g,
                       Graph::vertex_descriptor currNode,
                       Graph::vertex_descriptor goal,
                       stack<Graph::vertex_descriptor>& path)
{
    // Clear any visited nodes
    clearVisited(g);
    // DFS Recursion
    return DFSRecursive(g, currNode, goal, path);
}

/**
 * The non-recursive implementation of DFS. This function uses a stack to
 * contain nodes leading to a potential path. It looks at adjacent nodes and
 * continously iterates through them until it reaches the goal node.
 * @param g: A Graph object
 * @param currNode: The current node that is being visited
 * @param goal: The goal node to visit
 * @param path: A stack that contains the path
 * @return true if a path is found, false otherwise
 */
bool findPathNonRecursive(Graph& g,
                          Graph::vertex_descriptor start,
                          Graph::vertex_descriptor goal,
                          stack<Graph::vertex_descriptor>& path)
{
    // Clear any visited nodes
    clearVisited(g);
    bool isLocated = false;
    // Create a stack to store the path
    stack<Graph::vertex_descriptor> tempPath;
    tempPath.push(start);
    Graph::vertex_descriptor currNode;

    // Keep looping until the we found a valid path and stack has a node
    while(!tempPath.empty() && !isLocated)
    {
        currNode = tempPath.top();
        tempPath.pop();
        // Check if the vertex hasn't been visited
        if (!g[currNode].isVisited)
        {
            // If the current node is the goal position, path is found
            if (currNode == goal)
            {
                isLocated = true;
            }
            g[currNode].isVisited = true;
            // Get adjacent vertices
            pair<Graph::adjacency_iterator, Graph::adjacency_iterator>
                    nodeRange = adjacent_vertices(currNode, g);
            // Loop through all adjacent nodes
            for (Graph::adjacency_iterator vertxIter = nodeRange.first;
                 vertxIter != nodeRange.second; ++vertxIter)
            {
                // If the node is not visited, set that as next possible node
                if (!g[*vertxIter].isVisited)
                {
                    g[*vertxIter].prev_node = currNode;
                    tempPath.push(*vertxIter);
                }
            }
        }
    }
    // If a path is found, add the current node to the path and go back to
    // previous nodes and add them to path until an invalid node arises.
    if (isLocated)
    {
        while (currNode != -1)
        {
            path.push(currNode);
            currNode = g[currNode].prev_node;
        }
    }
    return isLocated;
}

bool findShortestPath1(Graph& g,
                       Graph::vertex_descriptor start,
                       Graph::vertex_descriptor goal,
                       stack<Graph::vertex_descriptor>& path)
{
    // Clean up
    clearPrev(g);
    clearVisited(g);
    bool isLocated = false;

    // Queue based BFS implementation
    queue<Graph::vertex_descriptor> bfsQ;
    bfsQ.push(start);
    Graph::vertex_descriptor currNode;

    // Loop while the q is not empty and no path found
    while(!bfsQ.empty() && !isLocated)
    {
        // Get current shortest node and pop
        currNode = bfsQ.front();
        bfsQ.pop();
        // Check if visited
        if (!g[currNode].isVisited)
        {
            // If not, set to visited
            g[currNode].isVisited = true;
            // Check if the node is the goal node
            if (currNode == goal)
                isLocated = true;   // Found the node!
            // Otherwise we now iterate through adjacent nodes
            pair<Graph::adjacency_iterator, Graph::adjacency_iterator>
                nodeRange = adjacent_vertices(currNode, g);
            for (Graph::adjacency_iterator nodeItr = nodeRange.first;
                 nodeItr != nodeRange.second; ++nodeItr)
            {
                // If the node is not visited, set the previous node as the
                // current node. This means we took the least cost path we
                // currently know of.
                if (!g[*nodeItr].isVisited)
                {
                    g[*nodeItr].prev_node = currNode;
                    bfsQ.push(*nodeItr);
                }
            }
        }
    }
    // If we found a path, go through previous nodes to get path
    if (isLocated)
    {
        currNode = goal;
        while (currNode != start)
        {
            path.push(currNode);
            currNode = g[currNode].prev_node;
        }
        path.push(start);
    }
    return isLocated;
}

Graph::vertex_descriptor getMinWeight(Graph g, Graph::vertex_descriptor start)
{
    // Get node with min distance from source
    pair<Graph::adjacency_iterator, Graph::adjacency_iterator>
            nodeRange = adjacent_vertices(start, g);
    Graph::vertex_descriptor minWeight = *nodeRange.first;
    for (Graph::adjacency_iterator itr = nodeRange.first;
         itr != nodeRange.second; ++itr)
    {
        if (g[*itr].weight < minWeight && !g[*itr].isVisited)
            minWeight = *itr;
    }

    return minWeight;
}

void updateValues(Graph& g,
                  Graph::vertex_descriptor u,
                  Graph::vertex_descriptor v)
{
    pair<Graph::edge_descriptor, bool> edg = edge(u, v, g);
    if (g[v].weight > (g[u].weight + g[edg.first].weight))
    {
        g[v].weight = g[u].weight + g[edg.first].weight;
        g[v].prev_node = u;
    }
}

bool findShortestPath2(Graph& g,
                       Graph::vertex_descriptor start)
{
    // Clean up
    clearVisited(g);
    clearPrev(g);

    // Init Dijkstra by setting all nodes to 'infinity' and starting node as 0
    setNodeWeights(g, MaxNumNodex);
    g[start].weight = 0;

    // Get shortest path for all nodes
    Graph::vertex_descriptor minWeight;
    pair<Graph::vertex_iterator, Graph::vertex_iterator> nodeRange = vertices(g);
    for (Graph::vertex_iterator nodeItr = nodeRange.first;
         nodeItr != nodeRange.second; ++nodeItr)
    {
        // Get node with minimum weight
        minWeight = getMinWeight(g, *nodeItr);
        g[minWeight].isVisited = true;

        // Update values of adjacent vertices
        pair<Graph::adjacency_iterator, Graph::adjacency_iterator>
                uRange = adjacent_vertices(minWeight, g);
        for (Graph::adjacency_iterator uIter = uRange.first;
             uIter != uRange.second; ++uIter)
        {
            pair<Graph::edge_descriptor, bool> e = edge(minWeight, *uIter, g);
            if (g[e.first].weight < 0)
                return false;
            updateValues(g, minWeight, *uIter);
        }
    }
    return true;
}
// Main function
int main()
{
    try
    {
        // Read the maze from the file.
        string fileName = "/home/osboxes/algo_ws/proj5/maze1.txt";
        ifstream fin;

        // Open the file
        fin.open(fileName.c_str());
        if (!fin)
        {
            cerr << "Cannot open " << fileName << endl;
            exit(1);
        }

        // Create the maze object
        maze m(fin);
        fin.close();

        // Create the graph and set its params
        Graph g;
        m.mapMazeToGraph(g);
        clearVisited(g);
        clearPrev(g);
        clearMarked(g);
        setNodeWeights(g, 1);

        // Starting position node
        Graph::vertex_descriptor start = m.getMap(0, 0);
        // End position node
        Graph::vertex_descriptor end = m.getMap(m.getRows() - 1, m.getCols() - 1);
        // Stack container for path
        stack<Graph::vertex_descriptor> recursivePath, nonRecursivePath,
                                        bfsPath, dijkstraPath;
        // Check if path was found
        bool foundRecursivePath = findPathRecursive(g, start, end,
                                                    recursivePath);
        bool foundNonRecursivePath = findPathNonRecursive(g, start, end,
                                                          nonRecursivePath);
        bool foundBFSPath = findShortestPath1(g, start, end, bfsPath);

        // Check if a path was found using recursion
        if (foundRecursivePath)
        {
            cout << "Found recursive path.\n";
            m.printPath(end, recursivePath, g);
        }
        else
            cout << "No recursive path exists.\n";

        // Check if a path was found using stack based DFS
        if (foundNonRecursivePath)
        {
            cout << "Found non-recursive path.\n";
            m.printPath(end, nonRecursivePath, g);
        }
        else
            cout << "No non-recursive path exists.\n";

        // Check if a path was found using queue based BFS
        if (foundBFSPath)
        {
            cout << "Found BFS path.\n";
            m.printPath(end, bfsPath, g);
        }
        else
            cout << "No BFS path exists.\n";
    }
    catch (indexRangeError &ex)
    {
        cout << ex.what() << endl; exit(1);
    }
    catch (rangeError &ex)
    {
        cout << ex.what() << endl; exit(1);
    }


}
