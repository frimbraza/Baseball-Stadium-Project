#ifndef GRAPH
#define GRAPH

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

#include "heap.h"

using namespace std;

/******************************************************************
* Node Struct
*	This structure holds a destination, a weight, and a pointer
*	to another node. This is used for the adjacency list that is a
*	linked list.
******************************************************************/
struct Node
{
    int dest;
    int weight;

    Node* next;
    Node(int inputDest, int inputWeight)
        : dest(inputDest), weight(inputWeight), next(NULL) {}
};

/******************************************************************
* AdjList Struct
*	This structure holds a head, which is the beginning of the
*	linked list.
******************************************************************/
struct AdjList
{
    Node* head;
};

/******************************************************************
* Edge Struct
*	This structure holds information for a weighted edge as well
*	as has the ability to copy another edge using the assignment
*	operator.
******************************************************************/
struct Edge
{
    int src;
    int dest;
    int DistWeight;
    void operator=(const Edge& other)
    {
        src = other.src;
        dest = other.dest;
        DistWeight = other.DistWeight;
    }
    Edge() {}
    Edge(int inputSrc, int inputDest, int inputWeight)
        : src(inputSrc), dest(inputDest), DistWeight(inputWeight) {}
};

/******************************************************************
* EdgeComparator Struct
*	This structure has an overloaded parenthesis operator that
*	simply compares two edges and returns true if the first Edge
*	has a lower weight the second.
******************************************************************/
struct EdgeComparator
{
    bool operator()(Edge first, Edge second)
    {
        return first.DistWeight < second.DistWeight;
    }
};

/******************************************************************
* DijkstraInfo Class
*	This class contains info on variables that store information
*   created by dijkstra algorithm. Includes the max distance array
*   and path array. This is for one single vertice.
******************************************************************/
struct DijkstraInfo
{
    int cityNumber;
    string cityName;
    int* maxDistArray;
    vector<string>* pathArray;

    DijkstraInfo() {}
};

/******************************************************************
* Graph Class
*	This class contains a list of vertices, and adjacency linked
*	list for each vertice, and a list that holds all the possible
*	edges. Note that, this only works for a bidirectional graphs.
*	This class also contains a function for calculating a full
*	dijkstras traversal as well as a way to get the minimum
*	spanning tree using krugal's algorithm.
******************************************************************/
class Graph
{
public:
    // Constructor
    Graph();                               // might need to add to default constructors
    // Overloaded Constructor
    Graph(const vector<string>& vertices);
    // Adds necessary information from an edge to all the lists
    void addEdge(string src, string dest, int dist);
    // Prints the adjlist to console
    void printAdjList();
    // Fills Dijkstra info for the given index
    void createDijkstras(int start);
    // Fills Dijkstra info for the given index
    void createDijkstras(string start); // creates dijkstras
    // Prints Dijkstra info for a string vertice
    void printDijkstras(string start);
    // overloaded for ints
    void printDijkstras(int start);
    // prints the minimum spanning tree
    void printMST();
    // finds the shortest distance among the selected cities given.
    void shortestTravel(vector<string> selectedCities, string start, vector<string>& shortestPath);
    // returns the distance between two points through dijkstras
    int returnDist(int city1, int city2);
    // a list of vertices
    vector<string> verticeList;

private:
    // Holds the adjacency arrays for each point
    AdjList* adjListArray;
    // Holds the edge list
    vector<Edge> edgeList;
    // Holds Dijkstra information
    DijkstraInfo* dijInfoArray;

    // adds edges to the frontier
    void addAdjEdgesToFrontier(Heap<Edge, EdgeComparator>& frontier, bool visitedNodes[], int index, int maxDistArray[]);
    // checks if adding the edge will create a cycle
    bool formCycle(vector<int> clusterList[], Edge edge);
    // updates the cluster(tree)
    void updateCluster(vector<int> clusterList[], Edge edge);
    // checks if all nodes have been visited, for the bool array passed
    bool allNodesVisited(bool visited[], int sz);
    // checks if a string input is within the string array
    int getIndex(string input, string list[], int listSize);
    // checks if a string input is within the string vector
    int getIndex(string input, const vector<string>& list);
    // initializes the city list using a an edge
    void initCityList(vector<string> & cityList, const vector<vector<string>>& edgeList);
    // checks if a string exists in a string vector
    bool existInList(const vector<string>& list, string value);
};

#endif // !GRAPH
