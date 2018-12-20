#pragma once

#include "Node.h"

using std::cout;

class TransactionNode : public Node
{
public:
	TransactionNode(const string &data = "", const int &units = 0) : Node(data) // Uses inheritance, Node is the base class
	{
		this->mUnits = units;
	}
	~TransactionNode();

	void setUnits(int const &newUnits);
	int getUnits() const;

	void printData();

private:
	int mUnits;
};