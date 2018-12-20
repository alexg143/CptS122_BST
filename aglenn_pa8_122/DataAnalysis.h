#pragma once

#include <fstream>
#include "BST.h"

using std::ifstream;
using std::getline;

class DataAnalysis
{
public:
	DataAnalysis();
	~DataAnalysis();

	void runAnalysis();

private:
	BST mTreeSold;
	BST mTreePurchased;
	ifstream mCsvStream;

	void openFile();
	void getLineData(int *units, string *type, string *transaction);
	void insertIntoTree(string const &newData, int const &newUnits, string const &transaction);
	void updateTree();
	void displayTrends();
};