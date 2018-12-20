#pragma once

#include "TransactionNode.h"

using std::endl;

class BST
{
public:
	BST();
	~BST();

	void setRoot(Node * const &newRoot);
	Node *getRoot() const;

	void insert(string const &newData, int const &newUnits);
	void inOrderTraversal();

	TransactionNode &findSmallest();
	TransactionNode &findLargest();
private:
	Node *mpRoot;

	void destroyTree(Node * const &pTree);
	void insert(Node * const &pTree, string const &newData, int const &newUnits);
	void inOrderTraversal(Node * const &pTree);
};