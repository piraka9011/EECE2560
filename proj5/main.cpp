/**
 *  EECE2560: Proj5b
 *	main.cpp
 *	Purpose: The main file has all the path finding functions and simulates
 *	the traversal of the map. It also finds the shortest paths using BFS and
 *	Dijkstra's algorithm.
 *	@author: Anas Abou Allaban & Turki Alrifaie
 *	@version: 2.0 4/20/17
 */

#include "maze.h"

Graph g;

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
 * @param start: The starting node
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

/**
 * findShortestPath1 gets the shortest path using the BFS algorithm. BFS is
 * implemented using a Queue structure, however the path is found by tracing
 * the goal node's previous nodes continuously as that is a property of the
 * nodes.
 * @param g: A Graph object
 * @param start: The starting node
 * @param goal: The goal node to visit
 * @param path: A stack that contains the path
 * @return true if a path is found, false otherwise
 */
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

/**
 * Utility structure to allow for comparison of nodes from the boost library.
 * Basis of comparison are the node's NodeProperty weights. Structure is used
 * to make a minimum heap using STL make_heap.
 */
struct MinNodeCompare
{
    bool operator() (Graph::vertex_descriptor const& lhs,
                     Graph::vertex_descriptor const& rhs)
    {
        return g[lhs].weight > g[rhs].weight;
    }
};

/**
 * findShortestPath2 finds the shortest path using Dijkstra's algorithm for
 * shortest paths. The 'Priority queue' used to see which node to visit next
 * is implemented as a vector that is min-heapified to get the nodes with the
 * smallest weights first.
 * @param g: A graph object
 * @param start: The starting node
 * @param goal: The goal node to visit
 * @param path: A stack that contains the path
 * @return true if a path is found, false otherwise
 */
bool findShortestPath2(Graph& g,
                       Graph::vertex_descriptor start,
                       Graph::vertex_descriptor goal,
                       stack<Graph::vertex_descriptor>& path)
{
    // Clean up
    clearVisited(g);        // Mark all vertices unvisited
    clearVisitedEdge(g);    // Mark all edges unvisited
    clearPrev(g);           // Clear saved previous nodes

    // Init Dijkstra
    setNodeWeights(g, MaxNumNodex); // Set shortest path = inf
    setEdgeWeights(g, 1);           // Set all edge weights to 1 (undirected graph)
    g[start].weight = 0;            // Set sp for startVertex = 0

    // Push all vertices into 'priority queue'
    vector<Graph::vertex_descriptor> dijkstraHeap;
    pair<Graph::vertex_iterator, Graph::vertex_iterator> nodeRange = vertices(g);
    for (Graph::vertex_iterator nodeItr = nodeRange.first;
         nodeItr != nodeRange.second; ++nodeItr)
        dijkstraHeap.push_back(*nodeItr);

    // Make a min heap
    make_heap(dijkstraHeap.begin(), dijkstraHeap.end(), MinNodeCompare());

    // Create vars
    Graph::vertex_descriptor currNode;
    bool isLocated = false;

    // Get shortest path: loop while pQ not empty and path not found
    while(!dijkstraHeap.empty() && !isLocated)
    {
        // Update queue and get node with minimum weight (v)
        make_heap(dijkstraHeap.begin(), dijkstraHeap.end(), MinNodeCompare());
        currNode = dijkstraHeap.front();
        dijkstraHeap.erase(dijkstraHeap.begin());

        // Goal reached
        if (currNode == goal)
            isLocated = true;
        else
        {
            // Mark v as visited
            g[currNode].isVisited = true;

            // For all unvisited neighbors w of v, update weights
            pair<Graph::adjacency_iterator, Graph::adjacency_iterator>
                    uRange = adjacent_vertices(currNode, g);
            for (Graph::adjacency_iterator uIter = uRange.first;
                 uIter != uRange.second; ++uIter)
            {
                Graph::vertex_descriptor testNode = *uIter;
                // Check if not visited
                if (!g[*uIter].isVisited)
                {
                    pair<Graph::edge_descriptor, bool> e = edge(currNode, *uIter, g);
                    // If its a new shortest path (weight change) set parent w to v
                    if (g[*uIter].weight > g[currNode].weight + g[e.first].weight)
                    {
                        g[*uIter].weight = g[currNode].weight + g[e.first].weight;
                        g[*uIter].prev_node = currNode;
                    }
                }
            }
        }
    }

    // Create path if path is found
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

// Main function
int main()
{
    try
    {
        // Read the maze from the file.
        string fileName = "/home/osboxes/algo_ws/proj5/maze2.txt";
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
        bool foundDijkstraPath = findShortestPath2(g, start, end, dijkstraPath);

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
        // Check if a path was found using Dijkstra
        if (foundDijkstraPath)
        {
            cout << "Found Dijkstra path.\n";
            m.printPath(end, dijkstraPath, g);
        }
        else
            cout << "No Dijkstra path exists.\n";
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
