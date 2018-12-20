#include "Node.h"

Node::Node(const string &data) // Constructor
{
	this->mData = data;
	this->mpLeft = nullptr;
	this->mpRight = nullptr;
}

Node::~Node() // Destructor
{
	// Nodes deleted in BST destructor
}

// Setters
void Node::setData(string const &newData) 
{
	this->mData = newData;
}

void Node::setLeft(Node * const &newPLeft)
{
	this->mpLeft = newPLeft;
}

void Node::setRight(Node * const &newPRight)
{
	this->mpRight = newPRight;
}

// Getters
string Node::getData() const
{
	return this->mData;
}

Node *Node::getLeft() const
{
	return this->mpLeft;
}

Node *Node::getRight() const
{
	return this->mpRight;
}