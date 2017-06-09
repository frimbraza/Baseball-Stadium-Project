#ifndef HEAP
#define HEAP

#include <iostream>

using namespace std;

/******************************************************************
* Heap Class
*	This is the Heap class that allows you to take inputs of any
*		type and a comparator for the type, and stores the inputs
*		into a heap tree data structure based on the comparator.
******************************************************************/
template<typename T, typename C>
class Heap
{
private:
    // Private Variables
    // The Heap Tree is stored in a pointer array
    T** HeapTree;
    // The max number of elements of the tree
    int capacity;
    // The last empty index in the heap tree array
    int lastNodeLocation;

    //Private Functions
    // Sort the Heap upwards from nodeLocation
    void upHeap(int nodeLocation);
    // Sort the Heap downwards from nodeLocation
    void downHeap(int nodeLocation);
    // Add a level to the heap tree.
    void addLevel();

public:
    // Constructor
    Heap();
    // Destructor
    ~Heap();
    // Insert a value into the heap tree
    void insert(T value);
    // Remove the top of the heap, and sort
    T remove();
    // Returns whether or not the heap is empty
    bool isEmpty() { return !HeapTree[0]; }
    // Prints the Heap in Pre-Order
    void printPreOrder(int start = 0);
    // Prints the array as is
    void printHeapArray();
};

#endif // !HEAP

/********************************************************************
* O(n) where n is the heaps height
* upHeap : Class Heap
*___________________________________________________________________
* This up-heaps(sorts) the heap tree from the location of a node
*	that is normally a leaf. Often used in insertion. Note that
*	this will only affect the node and all its parents.
*___________________________________________________________________
* PRE-CONDITIONS
*	nodeLoc : the index in which to up-heap from.
*
* POST-CONDITIONS
*	The tree should be sorted based on the index given.
********************************************************************/
template<typename T, typename C>
void Heap<T, C>::upHeap(int nodeLoc)
{
    C hiPri;								// Comparator, if first > second -> true, False otherwise
    T thisValue = *HeapTree[nodeLoc];
    int parentLoc = (nodeLoc - 1) / 2;		// Find your parent T.T *Note can be negative, but won't matter
    T parentValue = *HeapTree[parentLoc];
    if (nodeLoc == 0)						// Reached end -> return
        return;
    if (!hiPri(thisValue, parentValue))		// Correct place ->return
        return;

    T* tempNodePtr = HeapTree[parentLoc];
    HeapTree[parentLoc] = HeapTree[nodeLoc];		// Swap them
    HeapTree[nodeLoc] = tempNodePtr;

    upHeap(parentLoc);						// Call recursively
}

/********************************************************************
* O(n) where n is the number of recursions(height)
* downHeap : Class Heap
*___________________________________________________________________
* This down-heaps(sorts) the heap tree from the location of a node
*	that is normally the root. Often used in remove. Note that
*	this can affect the whole tree.
*___________________________________________________________________
* PRE-CONDITIONS
*	nodeLoc : the index in which to down-heap from.
*
* POST-CONDITIONS
*	The tree should be sorted based on the index given.
********************************************************************/
template<typename T, typename C>
void Heap<T, C>::downHeap(int nodeLoc)
{
    if ((2 * nodeLoc + 1) >= lastNodeLocation)		// you reached a leaf so return
        return;
    C hiPri;
    T thisValue = *HeapTree[nodeLoc];
    T leftChild = *HeapTree[2 * nodeLoc + 1];
    if ((2 * nodeLoc + 2) >= lastNodeLocation)			// If only the left child exists
    {
        if (hiPri(leftChild, thisValue))				// Compare the left and this value only
        {
            T* tempNodePtr = HeapTree[nodeLoc];
            HeapTree[nodeLoc] = HeapTree[2 * nodeLoc + 1];
            HeapTree[2 * nodeLoc + 1] = tempNodePtr;
            downHeap(2 * nodeLoc + 1);
        }
    }
    else
    {
        T rightChild = *HeapTree[2 * nodeLoc + 2];			// Both children exists
        if (hiPri(leftChild, rightChild))					// Compare left & right
        {
            if (hiPri(leftChild, thisValue))				// if left was bigger, compare left and this
            {
                T* tempNodePtr = HeapTree[nodeLoc];
                HeapTree[nodeLoc] = HeapTree[2 * nodeLoc + 1];
                HeapTree[2 * nodeLoc + 1] = tempNodePtr;
                downHeap(2 * nodeLoc + 1);
            }
        }
        else
        {
            if (hiPri(rightChild, thisValue))				// if right was bigger than left, compare right and this
            {
                T* tempNodePtr = HeapTree[nodeLoc];
                HeapTree[nodeLoc] = HeapTree[2 * nodeLoc + 2];
                HeapTree[2 * nodeLoc + 2] = tempNodePtr;
                downHeap(2 * nodeLoc + 2);
            }
        }
    }
}

/********************************************************************
* O(n) where n is the number of elements in the old tree
* addLevel : Class Heap
*___________________________________________________________________
* This adds a level to the heap tree and takes to account the
*	current highest level of the tree and creates a new array with the
*	appropriate amount of space for the array.
*___________________________________________________________________
* PRE-CONDITIONS
*	none
*
* POST-CONDITIONS
*	The heap tree array should have enough space for a new level
*		 of the tree.
********************************************************************/
template<typename T, typename C>
void Heap<T, C>::addLevel()
{
    int newCapacity = 2 * capacity + 1;
    T** newHeapTree = new T*[newCapacity];
    for (int i = 0; i < newCapacity; ++i)
    {
        if (i < capacity)
            newHeapTree[i] = this->HeapTree[i];
        else
            newHeapTree[i] = 0;
    }
    capacity = newCapacity;
    delete[] HeapTree;
    this->HeapTree = newHeapTree;
}

/********************************************************************
* O(C)
* Heap : Class Heap
*___________________________________________________________________
* This is the constructor for the heap class. It initializes an
*	an empty tree and sets a generic capacity meant for a tree with
*	4 levels.
*___________________________________________________________________
* PRE-CONDITIONS
*	none
*
* POST-CONDITIONS
*	A new empty heap object should be made with capacity for 31
*		elements
********************************************************************/
template<typename T, typename C>
Heap<T, C>::Heap()
{
    capacity = 31; // Note: level 0 = 1 elements, 1 = 3, 2 = 7, 3 = 15, 4 = 31
    HeapTree = new T*[capacity];
    for (int i = 0; i < capacity; ++i)
    {
        HeapTree[i] = 0;
    }
    lastNodeLocation = 0;
}

/********************************************************************
* O(n) where n is the number of elements to remove
* ~Heap : Class Heap
*___________________________________________________________________
* This is the destructor for the heap class. It removes from the
*	heap until empty.
*___________________________________________________________________
* PRE-CONDITIONS
*	none
*
* POST-CONDITIONS
*	The Heap Object should be deleted
********************************************************************/
template<typename T, typename C>
Heap<T, C>::~Heap()
{
    while (!isEmpty())
    {
        remove();
    }
    delete[] HeapTree;
}

/********************************************************************
* O(n) where n is the height of the tree to search
* Insert : Class Heap
*___________________________________________________________________
* This inserts the value into the heap tree array. If the tree is
*	at max capacity it will call a resize. It will also call an
*	up-heap from the location at which the value is stored.
*___________________________________________________________________
* PRE-CONDITIONS
*	value : The value to be inserted.
*
* POST-CONDITIONS
*	The Heap should have a new element added that is properly
*		sorted
********************************************************************/
template<typename T, typename C>
void Heap<T, C>::insert(T value)
{
    if (lastNodeLocation == capacity)
        addLevel();
    T* nodePtr = new T; // Trying to make a new ptr to the value(whatever it may be). Is this the right syntax?
    *nodePtr = value;	// Now I set the dereference ptr equal to the value.
    HeapTree[lastNodeLocation] = nodePtr;
    upHeap(lastNodeLocation);
    lastNodeLocation++;
}

/********************************************************************
* O(n) where n is the height of the tree
* Remove : Class Heap
*___________________________________________________________________
* This removes the top of the heap and resorts the heap tree.
*___________________________________________________________________
* PRE-CONDITIONS
*	none
*
* POST-CONDITIONS
*	The Heap should have one less element and still be sorted.
********************************************************************/
template<typename T, typename C>
T Heap<T, C>::remove()
{
    T top;
    if (!isEmpty())
    {
        top = *HeapTree[0];
//        T tempValue = *HeapTree[0];
        delete HeapTree[0];
        HeapTree[0] = HeapTree[lastNodeLocation - 1];	// set root to Last filled Node
        HeapTree[lastNodeLocation - 1] = 0;
        lastNodeLocation--;
        downHeap(0);
    }
    return top;
}

/********************************************************************
* O(n) where n is how many elements are in the tree
* printPreOrder : Class Heap
*___________________________________________________________________
* Prints the heap in pre-order, starting at the root.
*___________________________________________________________________
* PRE-CONDITIONS
*	start : This is defaulted to index 0 which is the root.
*
* POST-CONDITIONS
*	The heap should be printed to console in pre-order.
********************************************************************/
template<typename T, typename C>
void Heap<T, C>::printPreOrder(int start)
{
    if (start >= lastNodeLocation)
        return;
    cout << *HeapTree[start] << " ";
    printPreOrder(2 * start + 1);
    printPreOrder(2 * start + 2);
}

/********************************************************************
* O(n) where n is the number of elements in the heap
* printHeapArray : Class Heap
*___________________________________________________________________
* This prints the heap tree in the order that the array is in.
*___________________________________________________________________
* PRE-CONDITIONS
*	none
*
* POST-CONDITIONS
*	The Heap should be printed to console in the order of the array.
********************************************************************/
template<typename T, typename C>
void Heap<T, C>::printHeapArray()
{
    for (int i = 0; i < lastNodeLocation; ++i)
    {
        cout << *HeapTree[i] << " ";
    }
}
