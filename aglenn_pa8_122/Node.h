#pragma once

#include <iostream>
#include <string>

using std::string;

class Node
{
public:
	Node(const string &data = "");
	virtual ~Node(); // Virtual destructor

	void setData(string const &newData);
	void setLeft(Node * const &newPLeft);
	void setRight(Node * const &newPRight);

	string getData() const;
	Node *getLeft() const;
	Node *getRight() const;

	virtual void printData() = 0; // Pure virtual print function

protected:
	string mData;
	Node *mpLeft;
	Node *mpRight;
};