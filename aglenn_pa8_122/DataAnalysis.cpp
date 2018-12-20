#include "DataAnalysis.h"

// Public Functions ----------------------------------------------------------------------------------------------

/*Function: DataAnalysis()
  Description: Constructor.
*/
DataAnalysis::DataAnalysis()
{
	this->mCsvStream;
	this->mTreePurchased;
	this->mTreeSold;
}

/*Function: ~DataAnalysis()
  Description: Destructor.
*/
DataAnalysis::~DataAnalysis()
{
	// destructors from other classes will be called
}

/*Function: runAnalysis()
  Description: Runs the analysis using the private functions.
*/
void DataAnalysis::runAnalysis()
{
	this->openFile();
	this->updateTree();
	this->displayTrends();
}

// Private Functions ---------------------------------------------------------------------------------------------

/*Function: openFile()
  Description: Opens data.csv for read using mCsvStream.
*/
void DataAnalysis::openFile()
{
	this->mCsvStream.open("data.csv", std::ios::in);
}

/*Function: getLineData()
  Description: Gets the necessary data from a line of the file. This data is returned
			   using pointers in the parameter.
*/
void DataAnalysis::getLineData(int *units, string *type, string *transaction)
{
	string tempLine = "";

	getline(this->mCsvStream, tempLine, ',');
	*units = atoi(tempLine.c_str());

	getline(this->mCsvStream, tempLine, ',');
	*type = tempLine;

	getline(this->mCsvStream, tempLine, '\n');
	*transaction = tempLine;
}

/*Function: insertIntoTree()
  Description: Inserts the data into each tree based on the transaction type.
*/
void DataAnalysis::insertIntoTree(string const &newData, int const &newUnits, string const &transaction)
{
	if (transaction == "Purchased")
	{
		this->mTreePurchased.insert(newData, newUnits);
	}
	else if(transaction == "Sold")
	{
		this->mTreeSold.insert(newData, newUnits);
	}
}

/*Function: updateTree()
  Description: Reads the file line by line and inserts the data into the tree. Prints
			   the contents of both trees.
*/
void DataAnalysis::updateTree()
{
	int units;
	string data, transaction;

	int *pUnits = &units;
	string *pData = &data;
	string *pTransaction = &transaction;

	this->getLineData(pUnits, pData, pTransaction);

	while (!(this->mCsvStream.eof()))
	{
		this->getLineData(pUnits, pData, pTransaction);
		this->insertIntoTree(data, units, transaction);
	}

	cout << "Purchased (Type, Units): \n";
	this->mTreePurchased.inOrderTraversal();
	cout << "\nSold (Type, Units): \n";
	this->mTreeSold.inOrderTraversal();
}

/*Function: displayTrends()
  Description: Uses both trees as well as the findSmallest and findLargest functions to
			   print the purchase trends.
*/
void DataAnalysis::displayTrends()
{
	TransactionNode tempNode;

	cout << "\n\n";
	tempNode = this->mTreePurchased.findSmallest();
	cout << "Least Purchased: ";
	tempNode.printData();
	cout << endl;
	cout << "Most Purchased: ";
	tempNode = this->mTreePurchased.findLargest();
	tempNode.printData();

	cout << "\n\n";
	tempNode = this->mTreeSold.findSmallest();
	cout << "Least Sold: ";
	tempNode.printData();
	cout << endl;
	cout << "Most Sold: ";
	tempNode = this->mTreeSold.findLargest();
	tempNode.printData();
	cout << "\n\n";
}