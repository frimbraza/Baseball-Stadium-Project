#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <vector>

using namespace std;

template<typename E>
struct TreeNode
{
    E value;
    TreeNode<E> *left;
    TreeNode<E> *right;
    TreeNode<E>()
    {
        value = E();
        left = NULL;
        right = NULL;
    }
};

template<typename E, typename C>
class BinaryTree {
private:
    TreeNode<E>* root;
	C higherPriority;
    void insert(TreeNode<E> *& nodePtr, TreeNode<E> *&newNode);
    void destroySubTree(TreeNode<E> *nodePtr);
    void deleteNode(E, TreeNode<E> *& nodePtr);
    void makeDeletion(TreeNode<E> *& nodePtr);
    void displayInOrder(TreeNode<E> *nodePtr) const;
    void displayPreOrder(TreeNode<E> *nodePtr) const;
    void displayPostOrder(TreeNode<E> *nodePtr) const;
    int getSize(TreeNode<E> *nodePtr) const;
    void copy(TreeNode<E>*& current, const TreeNode<E> *other);

    void inOrderItemList(vector<E>& itemList, TreeNode<E> *nodePtr);
public:
    BinaryTree() { root = NULL; }
    BinaryTree(const BinaryTree& other);
    void operator=(const BinaryTree& other);
    ~BinaryTree() { destroySubTree(root); }
    void insertNode(E);
    bool searchNode(E);
    E getValue(E);
    E getRootValue();
    void remove(E);
    // void displayInOrder() const { displayInOrder(root); }
    // void displayPreOrder() const { displayPreOrder(root); }
    // void displayPostOrder() const { displayPostOrder(root); }
    int getSize() const { return getSize(root); }

    // Functions added for stadium project 6/1/2017
    void inOrderItemList(vector<E>& itemList);
};

template<typename E, typename C>
inline BinaryTree<E, C>::BinaryTree(const BinaryTree<E, C> & other)
{
    copy(root, other.root);
}

template<typename E, typename C>
inline void BinaryTree<E, C>::operator=(const BinaryTree<E, C> & other)
{
    destroySubTree(root);
    copy(root, other.root);
}

template<typename E, typename C>
void BinaryTree<E, C>::insertNode(E item) {
    TreeNode<E>* newNode = new TreeNode<E>;

    newNode->value = item;
    newNode->left = newNode->right = NULL;

    //Insert the Node
    insert(root, newNode);
}

template<typename E, typename C>
void BinaryTree<E, C>::insert(TreeNode<E> *&nodePtr, TreeNode<E> *&newNode) {
    if (nodePtr == NULL)
        nodePtr = newNode;
	else if (higherPriority(newNode->value,nodePtr->value))
        insert(nodePtr->left, newNode);
    else
        insert(nodePtr->right, newNode);
}

/*
template<typename E, typename C>
void BinaryTree<E, C>::displayInOrder(TreeNode<E> *nodePtr) const {
    if (nodePtr) {
        displayInOrder(nodePtr->left);
        cout << nodePtr->value << " ";
        displayInOrder(nodePtr->right);
    }
}

template<typename E, typename C>
void BinaryTree<E, C>::displayPreOrder(TreeNode<E> *nodePtr) const {
    if (nodePtr) {
        cout << nodePtr->value << " ";
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}

template<typename E, typename C>
void BinaryTree<E, C>::displayPostOrder(TreeNode<E> *nodePtr) const {
    if (nodePtr) {
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        cout << nodePtr->value << " ";
    }
}
*/

template<typename E, typename C>
void BinaryTree<E, C>::destroySubTree(TreeNode<E> *nodePtr) {
    while (nodePtr)
    {
        makeDeletion(nodePtr);
    }
}

template<typename E, typename C>
bool BinaryTree<E, C>::searchNode(E num) {
    TreeNode<E>* nodePtr = root;

    while (nodePtr) {
        if (nodePtr->value == num)
            return true;
        else if (higherPriority(num, nodePtr->value))
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }
    return false;
}

template<typename E, typename C>
inline E BinaryTree<E, C>::getValue(E num)
{
    TreeNode<E>* nodePtr = root;

    while (nodePtr) {
        if (nodePtr->value == num)
            return nodePtr->value;
        else if (higherPriority(num, nodePtr->value))
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }
}

template<typename E, typename C>
inline E BinaryTree<E, C>::getRootValue()
{
    if (root)
    {
        return root->value;
    }
    else
        return E();
}

template<typename E, typename C>
void BinaryTree<E, C>::remove(E num) {
    deleteNode(num, root);
}

template<typename E, typename C>
void BinaryTree<E, C>::deleteNode(E num, TreeNode<E> *&nodePtr) {
    if (higherPriority(num,nodePtr->value))
        deleteNode(num, nodePtr->left);
    else if (higherPriority(nodePtr->value,num))
        deleteNode(num, nodePtr->right);
    else
        makeDeletion(nodePtr);
}

template<typename E, typename C>
void BinaryTree<E, C>::makeDeletion(TreeNode<E> *&nodePtr) {
    TreeNode<E> *tempNodePtr;

    if (nodePtr == NULL)
        cout << "Cannot delete empty node\n";
    else if (nodePtr->right == NULL)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left;
        delete tempNodePtr;
    }
    else if (nodePtr->left == NULL)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
    //If the node has two Children
    else
    {
        //Move one node to the right
        tempNodePtr = nodePtr->right;
        //Go to the end left node
        while (tempNodePtr->left)
            tempNodePtr = tempNodePtr->left;
        //Reattach the left subtree
        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;
        //Reattach the right subtree
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
}

template<typename E, typename C>
inline int BinaryTree<E, C>::getSize(TreeNode<E>* nodePtr) const
{
    if (!nodePtr)
        return 0;
    else if ((!(nodePtr->left)) && (!(nodePtr->right)))
        return 1;
    else
    {
        return (1 + getSize(nodePtr->left) + getSize(nodePtr->right));
    }
}

template<typename E, typename C>
inline void BinaryTree<E, C>::copy(TreeNode<E>*& current, const TreeNode<E>* other)
{
    if (other == NULL)
    {
        current = NULL;
    }
    else
    {
        TreeNode<E>* tempNode = new TreeNode<E>;
        tempNode->value = other->value;
        current = tempNode;
        copy(current->left, other->left);
        copy(current->right, other->right);

    }
}

// New Functions
template<typename E, typename C>
inline void BinaryTree<E,C>::inOrderItemList(vector<E>& itemList,TreeNode<E>* nodePtr)
{
    if (nodePtr) {
        inOrderItemList(nodePtr->left);
        itemList.push_back(nodePtr->value);
        inOrderItemList(nodePtr->right);
    }
}

template<typename E, typename C>
inline void BinaryTree<E,C>::inOrderItemList(vector<E>& itemList)
{
    inOrderItemList(itemList, root);
}

#endif // BINARYTREE_H
