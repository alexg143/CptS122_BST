#include "TransactionNode.h"

TransactionNode::~TransactionNode() // Destructor
{
	// Nodes deleted in BST destructor
}

void TransactionNode::setUnits(int const &newUnits) // Setter
{
	this->mUnits = newUnits;
}

int TransactionNode::getUnits() const // Getter
{
	return this->mUnits;
}

void TransactionNode::printData() // Print function
{
	cout << this->mData << ", " << this->mUnits;
}