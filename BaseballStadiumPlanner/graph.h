#ifndef GRAPH
#define GRAPH

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

#include "heap.h"

using namespace std;

struct Node
{
    int dest;
    int weight;

    Node* next;
    Node(int inputDest, int inputWeight)
        : dest(inputDest), weight(inputWeight), next(NULL) {}
};

struct AdjList
{
    Node* head;
};

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

struct EdgeComparator
{
    bool operator()(Edge first, Edge second)
    {
        return first.DistWeight < second.DistWeight;
    }
};

struct DijkstraInfo
{
    int cityNumber;
    string cityName;
    int* maxDistArray;
    vector<string>* pathArray;

    DijkstraInfo() {}
};

class Graph
{
public:
    Graph();                               // might need to add to default constructors
    Graph(const vector<string>& vertices);
    void addEdge(string src, string dest, int dist);
    void printAdjList();

    void createDijkstras(int start);
    void createDijkstras(string start); // creates dijkstras

    void printDijkstras(string start);
    void printDijkstras(int start);

    void printMST();

    void shortestTravel(vector<string> selectedCities, string start, vector<string>& shortestPath);

    int returnDist(int city1, int city2);

    vector<string> verticeList;

private:

    AdjList* adjListArray;
    vector<Edge> edgeList;

    DijkstraInfo* dijInfoArray;

    void addAdjEdgesToFrontier(Heap<Edge, EdgeComparator>& frontier, bool visitedNodes[], int index, int maxDistArray[]);
    bool formCycle(vector<int> clusterList[], Edge edge);
    void updateCluster(vector<int> clusterList[], Edge edge);

    bool allNodesVisited(bool visited[], int sz);

    int getIndex(string input, string list[], int listSize);
    int getIndex(string input, const vector<string>& list);

    void initCityList(vector<string> & cityList, const vector<vector<string>>& edgeList);
    bool existInList(const vector<string>& list, string value);
    // bool pathRecursion(string current, bool visited[], int sz, vector<string> selectedCites, vector<string>& path);
};

#endif // !GRAPH
