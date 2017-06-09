#include "graph.h"


/********************************************************************
* O(n^2) where n is the number of vertices
* Graph : Class Graph
*___________________________________________________________________
* The graph constructor that initializes with a vector of strings
*___________________________________________________________________
* PRE-CONDITIONS
*	vertices : a vector of unique strings
*
* POST-CONDITIONS
*	Graph should be instantiated with it's vertice list created with
*	the size equal to the number of vertices, all initialized to null.
********************************************************************/
Graph::Graph()
{
    vector<vector<string>> edgeHolder;
    vector<string> vertices;

    string line;
    ifstream infile("BaseballStadiumEdgeList.txt");
    while (getline(infile, line))
    {
        istringstream iss(line);
        vector<string> stringEdge;
        string token;
        while (getline(iss, token, ','))
        {
            stringEdge.push_back(token);
        }
        edgeHolder.push_back(stringEdge);				// Fill the edge list
    }
    infile.close();

    initCityList(vertices, edgeHolder);					// initialize the city list

    // cout << vertices.size() << "!!!!!!" <<endl;

    verticeList = vertices;
    adjListArray = new AdjList[verticeList.size()];
    for (int i = 0; i < (int)verticeList.size(); ++i)
    {
        adjListArray[i].head = NULL;
    }

    for(int i = 0; i < (int)verticeList.size(); ++i)
    {
        dijInfoArray = new DijkstraInfo[verticeList.size()];
    }
    for (int i = 0; i < (int)verticeList.size(); ++i)
    {
        dijInfoArray[i].maxDistArray = new int[verticeList.size()];
        dijInfoArray[i].pathArray = new vector<string>[verticeList.size()];
        dijInfoArray[i].cityNumber = i;
        dijInfoArray[i].cityName = verticeList[i];
    }

    for (int i = 0; i < (int)edgeHolder.size(); ++i)
    {
        int distance = stoi(edgeHolder[i][2]);
        addEdge(edgeHolder[i][0], edgeHolder[i][1], distance);	// Actually adds the edges to the graph object, travelMap
    }

    for (int i = 0; i < (int)vertices.size(); ++i)
    {
        createDijkstras(i);
    }

}

/********************************************************************
* O(n) where n is the number of vertices
* Graph : Class Graph
*___________________________________________________________________
* The graph constructor that initializes with a vector of strings
*___________________________________________________________________
* PRE-CONDITIONS
*	vertices : a vector of unique strings
*
* POST-CONDITIONS
*	Graph should be instantiated with it's vertice list created with
*	the size equal to the number of vertices, all initialized to null.
********************************************************************/
Graph::Graph(const vector<string>& vertices)
{
    verticeList = vertices;
    adjListArray = new AdjList[verticeList.size()];
    for (int i = 0; i < (int)verticeList.size(); ++i)
    {
        adjListArray[i].head = NULL;
    }

    for(int i = 0; i < (int)verticeList.size(); ++i)
    {
        dijInfoArray = new DijkstraInfo[verticeList.size()];
    }
    for (int i = 0; i < (int)verticeList.size(); ++i)
    {
        dijInfoArray[i].maxDistArray = new int[verticeList.size()];
        dijInfoArray[i].pathArray = new vector<string>[verticeList.size()];
        dijInfoArray[i].cityNumber = i;
        dijInfoArray[i].cityName = verticeList[i];
    }
}

/********************************************************************
* O(n)where n is the number of vertices
* addEdge : Class Graph
*___________________________________________________________________
* This function adds edge information into adjaceny list array and
*	the edge list.
*___________________________________________________________________
* PRE-CONDITIONS
*	src : the source vertice of the edge
*	dest : the destination vertice of the edge
*	dist : the distance between the two vertices
*
* POST-CONDITIONS
*	The adjacency list array and the edge list vector should be
*	filled with the input edge's infomration
********************************************************************/
void Graph::addEdge(string src, string dest, int dist)
{
    int srcIndex, destIndex;
    for (int i = 0; i < (int)verticeList.size(); ++i)
    {
        if (src == verticeList[i])
            srcIndex = i;
        if (dest == verticeList[i])
            destIndex = i;
    }

    Node* newNode = new Node(destIndex, dist);
    newNode->next = adjListArray[srcIndex].head;
    adjListArray[srcIndex].head = newNode;
    // Do the same because it is bi-directional
    newNode = new Node(srcIndex, dist);
    newNode->next = adjListArray[destIndex].head;
    adjListArray[destIndex].head = newNode;

    Edge theEdge(srcIndex, destIndex, dist);
    edgeList.push_back(theEdge);
}

/********************************************************************
* O(n) where is the number of adjacency lists
* printAdjList : Class Graph
*___________________________________________________________________
* This function prints the adjacency list array for each vertice
*___________________________________________________________________
* PRE-CONDITIONS
*	none
*
* POST-CONDITIONS
*	The adjacency list array information should be printed to console
********************************************************************/
void Graph::printAdjList()
{
    for (int i = 0; i < (int)verticeList.size(); ++i)
    {
        cout << verticeList[i];
        Node* walker = adjListArray[i].head;
        while (walker)
        {
            string destination = verticeList[walker->dest];
            cout << " -> " << destination << ":" << walker->weight;
            walker = walker->next;
        }
        cout << endl;
    }
}

/* O(n) where n is the number of vertices
 * Overloaded create dijkstras function.
 *
 * Finds the string associated with the index, and sends string
 * Also calls createDijkstras
 */
void Graph::createDijkstras(int start)
{
    createDijkstras(verticeList[start]);
}

/* O(n) where n is the number of vertices
 * Creates dijkstras arrays. Those are max distance and path arrays.
 *
 * Needs a string paramater to create a custom dijkstra object for the string
 */
void Graph::createDijkstras(string start)
{
    // int* maxDistArray = new int[verticeList.size()];					// Max Distance Array
    // vector<string>* pathArray = new vector<string>[verticeList.size()];	// Paths for each Index
    int thisIndex;
    for (int i = 0; i < (int)verticeList.size(); ++i)
    {
        if (verticeList[i] == start)
        {
            thisIndex = i;
            break;
        }
    }
    int* maxDistArray = dijInfoArray[thisIndex].maxDistArray;
    vector<string>* pathArray = dijInfoArray[thisIndex].pathArray;

    Heap<Edge, EdgeComparator> frontier;								// Heap holding all the vertices, sorted my by minimum weight
    bool* visitedNodes = new bool[verticeList.size()];					// Vector bool check visited nodes

    for (int i = 0; i < (int)verticeList.size(); ++i)	// Set all visited nodes to false
        visitedNodes[i] = false;

    for (int i = 0; i < (int)verticeList.size(); ++i)	// Set the max distance array all = -1
        maxDistArray[i] = -1;

    int startIndex;										// The index of the node to start with
    for (int i = 0; i < (int)verticeList.size(); ++i)	// Search for index of the node to start with
    {
        if (verticeList[i] == start)
            startIndex = i;
    }

    maxDistArray[startIndex] = 0;								// Set max distance of the start index to 0
    pathArray[startIndex].push_back(verticeList[startIndex]);	// Set the path for the start index
    visitedNodes[startIndex] = true;							// Set the visited Node to true

                                                                // Fill the frontier with adjacent edges of the start node
    addAdjEdgesToFrontier(frontier, visitedNodes, startIndex, maxDistArray);

    // Emptying the frontier && Performing Dijkstras
    while (!frontier.isEmpty())
    {
        Edge shortEdge = frontier.remove();
        if (!visitedNodes[shortEdge.dest])
        {
            // add to distance, path, and visited array/vectors
            maxDistArray[shortEdge.dest] = shortEdge.DistWeight;

            for (int i = 0; i < (int)pathArray[shortEdge.src].size(); ++i)					// Add the past path to the src
            {
                pathArray[shortEdge.dest].push_back(pathArray[shortEdge.src][i]);
            }
            pathArray[shortEdge.dest].push_back(verticeList[shortEdge.dest]);				// Add the current vertice to the path
            visitedNodes[shortEdge.dest] = true;											// Set the vertice as visited


            addAdjEdgesToFrontier(frontier, visitedNodes, shortEdge.dest, maxDistArray);	// add new edges to frontier
        }
    }

    delete[] visitedNodes;
}


/********************************************************************
* O(n) where n is the number of vertices
* printDijkstras : Class Graph
*___________________________________________________________________
* This function calculates the minimal distance to each vertice from
*	a starting vertice and the path from it to console.
*___________________________________________________________________
* PRE-CONDITIONS
*	start : The vertice to start with.
*
* POST-CONDITIONS
*	The minimal distance and path from the starting vertice of every
*	vertice should be print to console.
********************************************************************/
void Graph::printDijkstras(string start)
{
    int thisIndex;
    for (int i = 0; i < (int)verticeList.size(); ++i)
    {
        if (verticeList[i] == start)
        {
            thisIndex = i;
            break;
        }
    }
    printDijkstras(thisIndex);
}


/********************************************************************
* O(n) where n is the number of vertices
* printDijkstras : Class Graph
*___________________________________________________________________
* This function calculates the minimal distance to each vertice from
*	a starting vertice and the path from it to console.
*___________________________________________________________________
* PRE-CONDITIONS
*	start : The vertice to start with.
*
* POST-CONDITIONS
*	The minimal distance and path from the starting vertice of every
*	vertice should be print to console.
********************************************************************/
void Graph::printDijkstras(int start)
{
    for (int i = 0; i < (int)verticeList.size(); ++i)
    {
        cout << verticeList[i] << " " << dijInfoArray[start].maxDistArray[i] << " ";
        cout << "{ " << dijInfoArray[start].pathArray[i][0];
        for (int j = 1; j < (int)dijInfoArray[start].pathArray[i].size(); ++j)
            cout << ", " << dijInfoArray[start].pathArray[i][j];
        cout << " }" << endl;
    }
}

/********************************************************************
* O(n^2) where n is the number of vertices
* printMST : Class Graph
*___________________________________________________________________
* This function calculates the edges that make up a minimum
*	spanning tree of the graph. Also prints the total weight of the
*	edges in the MST
*___________________________________________________________________
* PRE-CONDITIONS
*	none
*
* POST-CONDITIONS
*	The minimum spanning tree's edges are printed to console
********************************************************************/
void Graph::printMST()
{
    vector<Edge> MSTfinal;							// The Final MST
    Heap<Edge, EdgeComparator> minHeapEdgeList;		// The Heap to store all the edges, sorted with min on top
    for (int i = 0; i < (int)edgeList.size(); ++i)		// Fill the Heap
    {
        minHeapEdgeList.insert(edgeList[i]);
    }

    vector<int>* clusterList = new vector<int>[verticeList.size()]; // create a cluster tree list
    for (int i = 0; i < (int)verticeList.size(); ++i)					// initialize each vertice cluster to contain, itself
    {
        clusterList[i].push_back(i);
    }

    while (MSTfinal.size() != verticeList.size() - 1)				// An n number of vertices requires n-1 edges for a minimumm spanning tree
    {
        // if smallEdge doesn't form a cycle
        Edge smallEdge = minHeapEdgeList.remove();
        if (!formCycle(clusterList, smallEdge))
        {
            // Add small edge to the final MST
            MSTfinal.push_back(smallEdge);
            // add small edge to the cluster, make sure to include previous clusters
            updateCluster(clusterList, smallEdge);
        }
    }

    // printing the minimum spanning tree to console in a formatted way
    cout << "--------Minimum Spanning Tree---------\n";
    int totalMiles = 0;
    for (int i = 0; i < (int)MSTfinal.size(); ++i)
    {
        cout << i + 1 << ":("
            << verticeList[MSTfinal[i].src] << ", "
            << verticeList[MSTfinal[i].dest] << ") "
            << MSTfinal[i].DistWeight
            << endl;
        totalMiles += MSTfinal[i].DistWeight;
    }
    cout << endl << "Total Mileage = " << totalMiles << endl;

    delete[] clusterList;
}

/* O(n^2log(n))
 * shortest travel finds the shortest distance of a trip
 * while visiting all selected cities.
 *
 *
 * Input:
 *  vector<string> selectedCities : to hold the cities required
 *  string start : where to start in the search
 *  vector<string> the return container for the path
 */
void Graph::shortestTravel(vector<string> selectedCities, string start, vector<string>& shortestPath)	// return a vector of the sorted cities
{
    int totalDistance = 0; // some large number
    vector<string> path;
    bool* visitedNodes = new bool[selectedCities.size()];
    // bool* visitedNodes = new bool[verticeList.size()];

    for (int i = 0; i < (int)selectedCities.size(); ++i)	// Set all visited nodes to false
        visitedNodes[i] = false;

    int startIndex = getIndex(start, selectedCities);

    path.push_back(selectedCities[startIndex]);				// Set the path for the start index
    visitedNodes[startIndex] = true;						// Set the visited Node to true

    int currentIndex = getIndex(start, verticeList);
    while (!allNodesVisited(visitedNodes, selectedCities.size()))
    {
        vector<string>* currentPathArray = dijInfoArray[currentIndex].pathArray; // possibly wrong
        int* currentMaxDistArray = dijInfoArray[currentIndex].maxDistArray;		 // possibly wrong

        vector<int> possibleJumps;
        for (int i = 0; i < (int)verticeList.size(); ++i)
        {
            // string lastElement = currentPathArray[i][currentPathArray[i].size() - 1];
            string nextCity = verticeList[i];
            for (int j = 0; j < (int)selectedCities.size(); ++j)
            {
                if (nextCity == selectedCities[j] && !visitedNodes[j])
                {
                    possibleJumps.push_back(i);
                    break;
                }
            }
        }
        if (!possibleJumps.empty())
        {
            int lowestCityDist = 10000;
            int lowestCityIndex;
            for (int i = 0; i < (int)possibleJumps.size(); ++i)
            {
                if (currentMaxDistArray[possibleJumps[i]] < lowestCityDist)
                {
                    lowestCityDist = currentMaxDistArray[possibleJumps[i]];
                    lowestCityIndex = possibleJumps[i];
                }
            }
            for (int i = 1; i < (int)currentPathArray[lowestCityIndex].size(); ++i)
            {
                path.push_back(currentPathArray[lowestCityIndex][i]);
                if(existInList(selectedCities,currentPathArray[lowestCityIndex][i]))    // added these 2
                    visitedNodes[getIndex(currentPathArray[lowestCityIndex][i],selectedCities)] = true;          // added these 2
            }
            totalDistance += lowestCityDist;
            visitedNodes[getIndex(verticeList[lowestCityIndex], selectedCities)] = true;
            currentIndex = lowestCityIndex;
        }
        else
        {
            break;
        }
    }

    shortestPath = path;
}

/*
 * O(1)
 * returns the distance between two cities
 *
 * city1: int index of first
 * city2: int index of second
 */
int Graph::returnDist(int city1, int city2)
{
    int distance = dijInfoArray[city1].maxDistArray[city2];
    return distance;
}

void Graph::addAdjEdgesToFrontier(Heap<Edge, EdgeComparator>& frontier,
    bool visitedNodes[], int index, int maxDistArray[])
{
    Node* walker = adjListArray[index].head;	// Set walker to adjacency vector for start index
    while (walker)
    {
        if (!visitedNodes[walker->dest])
        {
            Edge newEdge(index, walker->dest, walker->weight + maxDistArray[index]);		// Make edge
            frontier.insert(newEdge);			// Add edge to frontier
        }
        walker = walker->next;					// Set walker to next adjacent edge
    }
}

/*********************************************************************
 * O(n) where n is the size of the current clusters
* formCycle : Class Graph
*___________________________________________________________________
* This function checks if an edge forms a cycle in the based off of
*	a list of clusters
*___________________________________________________________________
* PRE-CONDITIONS
*	clusterList : a cluster is collection of connected vertices and
*				  this list holds that information for each vertice
*	edge : This is the edge that will be added to the minimum
*		   spanning tree that must be checked if it forms a cycle
*
* POST-CONDITIONS
*	Returns true if a cycle is formed by the addition of an edge.
*	Returns false if no cycle is formed.
********************************************************************/
bool Graph::formCycle(vector<int> clusterList[], Edge edge)
{
    for (int i = 0; i < (int)clusterList[edge.src].size(); ++i)
    {
        if (clusterList[edge.src][i] == edge.dest)
            return true;
    }
    for (int i = 0; i < (int)clusterList[edge.dest].size(); ++i)
    {
        if (clusterList[edge.dest][i] == edge.src)
            return true;
    }
    return false;
}

/********************************************************************
* updateCluster : Class Graph
*___________________________________________________________________
* Updates the clusterList with the addition of an edge
*___________________________________________________________________
* PRE-CONDITIONS
*	clusterList : a cluster is collection of connected vertices and
*				  this list holds that information for each vertice
*	edge : This is the edge that will be added to the minimum
*		   spanning tree, and therefore the cluster list as it will
*		   form a new cluster or connect previous clusters.
* POST-CONDITIONS
*	The cluster list should be updated with the edge
********************************************************************/
void Graph::updateCluster(vector<int> clusterList[], Edge edge)
{
    vector<int> srcCluster = clusterList[edge.src];
    vector<int> destCluster = clusterList[edge.dest];

    for (int i = 0; i < (int)srcCluster.size(); ++i)
    {
        for (int j = 0; j < (int)destCluster.size(); ++j)
            clusterList[srcCluster[i]].push_back(destCluster[j]);
    }

    for (int i = 0; i < (int)destCluster.size(); ++i)
    {
        for (int j = 0; j < (int)srcCluster.size(); ++j)
            clusterList[destCluster[i]].push_back(srcCluster[j]);
    }
}

bool Graph::allNodesVisited(bool visited[], int sz)
{
    for (int i = 0; i < sz; ++i)
    {
        if (!visited[i])
            return false;
    }
    return true;
}

int Graph::getIndex(string input, string list[], int sz)
{
    for (int i = 0; i < sz; ++i)
    {
        if (list[i] == input)
            return i;
    }
    cout << "Not in list!!!!!!!!!!!!!!" << endl;
    return -1;
}

int Graph::getIndex(string input, const vector<string> &list)
{
    for (int i = 0; i < (int)list.size(); ++i)
    {
        if (input == list[i])
            return i;
    }
    return -1;
}

void Graph::initCityList(vector<string> & cityList, const vector<vector<string>>& edgeList)
{
    for (int i = 0; i < (int)edgeList.size(); ++i)
    {
        if (!existInList(cityList, edgeList[i][0]))		// Checks the source of the edge
            cityList.push_back(edgeList[i][0]);
        if (!existInList(cityList, edgeList[i][1]))		// Checks the destination of the edge
            cityList.push_back(edgeList[i][1]);
    }
}


bool Graph::existInList(const vector<string>& list, string value)
{
    for (int i = 0; i < (int)list.size(); ++i)
    {
        if (list[i] == value)
            return true;
    }
    return false;
}
