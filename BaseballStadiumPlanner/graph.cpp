#include "graph.h"


/* O(n) where n is the number of vertices
 * Graph default constructor
 *
 * initializes graph with a selected file edge list
 * and creates a dijkstra's array for each city.
 *
 * no paramaters
 */
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

/* O(n) where n is the number of vertices
 * An overloaded constructor
 *
 */
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

void Graph::createDijkstras(int start)
{
    createDijkstras(verticeList[start]);
}

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

    // printDijkstras(start);

    // Printing the information in a formatted output to console
    /*
    for (int i = 0; i < (int)verticeList.size(); ++i)
    {
        cout << verticeList[i] << " " << maxDistArray[i] << " ";
        cout << "{ " << pathArray[i][0];
        for (int j = 1; j < (int)pathArray[i].size(); ++j)
            cout << ", " << pathArray[i][j];
        cout << " }" << endl;
    }
    */
    // delete[] maxDistArray;
    // delete[] pathArray;
    delete[] visitedNodes;
}

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
            // cout << "Shouldn't reach here" << endl; // Remove this later
//            for (int i = 0; i < (int)selectedCities.size(); ++i)
//            {
//                if (!visitedNodes[i])
//                    possibleJumps.push_back(getIndex(selectedCities[i], verticeList));
//            }
//            if (possibleJumps.empty())
//            {
//                cout << "Your Done. Should never reach here." << endl;
//                break;
//            }
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
            /*
            int lowestCityDist = 100000;
            int lowestCityIndex;
            for (int i = 0; i < (int)possibleJumps.size(); ++i)
            {
                if (currentMaxDistArray[possibleJumps[i]] < lowestCityDist)
                {
                    lowestCityDist = currentMaxDistArray[possibleJumps[i]];
                    lowestCityIndex = possibleJumps[i];
                }
            }
            path.push_back(verticeList[lowestCityIndex]);
            totalDistance += lowestCityDist;
            visitedNodes[getIndex(verticeList[lowestCityIndex], selectedCities)] = true;
            currentIndex = lowestCityIndex;
            */
        }


    }

    shortestPath = path;
}

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
