#ifndef BINARY_TREE
#define BINARY_TREE

#include <iostream>

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

template<typename E>
class BinaryTree {
private:
	TreeNode<E>* root;
	void insert(TreeNode<E> *& nodePtr, TreeNode<E> *&newNode);
	void destroySubTree(TreeNode<E> *nodePtr);
	void deleteNode(E, TreeNode<E> *& nodePtr);
	void makeDeletion(TreeNode<E> *& nodePtr);
	void displayInOrder(TreeNode<E> *nodePtr) const;
	void displayPreOrder(TreeNode<E> *nodePtr) const;
	void displayPostOrder(TreeNode<E> *nodePtr) const;
	int leaf_count(TreeNode<E> *nodePtr) const;
	int non_leaf_count(TreeNode<E> *nodePtr) const;
	int getSize(TreeNode<E> *nodePtr) const;
	void copy(TreeNode<E>*& current, const TreeNode<E> *other);

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
	void displayInOrder() const { displayInOrder(root); }
	void displayPreOrder() const { displayPreOrder(root); }
	void displayPostOrder() const { displayPostOrder(root); }
	int leaf_count() const { return leaf_count(root); }
	int non_leaf_count() const { return non_leaf_count(root); }
	int getSize() const { return getSize(root); }
};

template<typename E>
inline BinaryTree<E>::BinaryTree(const BinaryTree<E> & other)
{
	copy(root, other.root);
}

template<typename E>
inline void BinaryTree<E>::operator=(const BinaryTree<E> & other)
{
	destroySubTree(root);
	copy(root, other.root);
}

template<typename E>
void BinaryTree<E>::insertNode(E num) {
	TreeNode<E>* newNode = new TreeNode<E>;

	newNode->value = num;
	newNode->left = newNode->right = NULL;

	//Insert the Node
	insert(root, newNode);
}

template<typename E>
void BinaryTree<E>::insert(TreeNode<E> *&nodePtr, TreeNode<E> *&newNode) {
	if (nodePtr == NULL)
		nodePtr = newNode;
	else if (newNode->value < nodePtr->value)
		insert(nodePtr->left, newNode);
	else
		insert(nodePtr->right, newNode);
}

template<typename E>
void BinaryTree<E>::displayInOrder(TreeNode<E> *nodePtr) const {
	if (nodePtr) {
		displayInOrder(nodePtr->left);
		cout << nodePtr->value << " ";
		displayInOrder(nodePtr->right);
	}
}

template<typename E>
void BinaryTree<E>::displayPreOrder(TreeNode<E> *nodePtr) const {
	if (nodePtr) {
		cout << nodePtr->value << " ";
		displayPreOrder(nodePtr->left);
		displayPreOrder(nodePtr->right);
	}
}

template<typename E>
void BinaryTree<E>::displayPostOrder(TreeNode<E> *nodePtr) const {
	if (nodePtr) {
		displayPostOrder(nodePtr->left);
		displayPostOrder(nodePtr->right);
		cout << nodePtr->value << " ";
	}
}

template<typename E>
void BinaryTree<E>::destroySubTree(TreeNode<E> *nodePtr) {
	while (nodePtr)
	{
		makeDeletion(nodePtr);
	}
	cout << "\nBinary Tree Destroyed\n";
}

template<typename E>
bool BinaryTree<E>::searchNode(E num) {
	TreeNode<E>* nodePtr = root;

	while (nodePtr) {
		if (nodePtr->value == num)
			return true;
		else if (num < nodePtr->value)
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}
	return false;
}

template<typename E>
inline E BinaryTree<E>::getValue(E num)
{
	TreeNode<E>* nodePtr = root;

	while (nodePtr) {
		if (nodePtr->value == num)
			return nodePtr->value;
		else if (num < nodePtr->value)
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}
}

template<typename E>
inline E BinaryTree<E>::getRootValue()
{
	if (root)
	{
		return root->value;
	}
	else
		return E();
}

template<typename E>
void BinaryTree<E>::remove(E num) {
	deleteNode(num, root);
}

template<typename E>
void BinaryTree<E>::deleteNode(E num, TreeNode<E> *&nodePtr) {
	if (num < nodePtr->value)
		deleteNode(num, nodePtr->left);
	else if (num > nodePtr->value)
		deleteNode(num, nodePtr->right);
	else
		makeDeletion(nodePtr);
}

template<typename E>
void BinaryTree<E>::makeDeletion(TreeNode<E> *&nodePtr) {
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

template<typename E>
int BinaryTree<E>::leaf_count(TreeNode<E> *nodePtr) const
{
	if (!nodePtr)
		return 0;
	else if ((!(nodePtr->left)) && (!(nodePtr->right)))
		return 1;
	else
		return (leaf_count(nodePtr->left) + leaf_count(nodePtr->right));
}

template<typename E>
int BinaryTree<E>::non_leaf_count(TreeNode<E> *nodePtr) const
{
	if (!nodePtr)
		return 0;
	else if ((!(nodePtr->left)) && (!(nodePtr->right)))
		return 0;
	else
	{
		return (1 + non_leaf_count(nodePtr->left) + non_leaf_count(nodePtr->right));
	}
}

template<typename E>
inline int BinaryTree<E>::getSize(TreeNode<E>* nodePtr) const
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

template<typename E>
inline void BinaryTree<E>::copy(TreeNode<E>*& current, const TreeNode<E>* other)
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

#endif //BINARY_TREE