#include "BST.h"

// Public Functions ----------------------------------------------------------------------------------------------

/*Function: BST()
  Description: Constructor.
*/
BST::BST()
{
	this->mpRoot = nullptr;
}

/*Function: BST()
  Description: Destructor. Calls the destroyTree() function,
			   which is private.
*/
BST::~BST()
{
	this->destroyTree(this->mpRoot);
}

/*Function: setRoot()
  Description: Sets the root node to a new root.
*/
void BST::setRoot(Node * const &newRoot)
{
	this->mpRoot = newRoot;
}

/*Function: getRoot()
  Description: Returns the root.
*/
Node *BST::getRoot() const
{
	return this->mpRoot;
}

/*Function: insert()
  Description: Overloaded function. Calls the private insert() function
			   to insert data and units into the tree.
*/
void BST::insert(string const &newData, int const &newUnits)
{
	this->insert(this->mpRoot, newData, newUnits);
}

/*Function: inOrderTraversal()
  Description: Overloaded function. Calls the private inOrderTraversal() function
			   to print the data in each node of the tree in order.
*/
void BST::inOrderTraversal()
{
	this->inOrderTraversal(this->mpRoot);
}

/*Function: findSmallest()
  Description: Returns a reference to a TransactionNode of the node with
			   the smallest units.
*/
TransactionNode & BST::findSmallest()
{
		Node *tempCur = this->mpRoot;
		Node *newTemp = nullptr;
		while (tempCur != nullptr) // traverse as much left as possible to find smallest value
		{
			tempCur = tempCur->getLeft();
			if (tempCur != nullptr)
			{
				newTemp = tempCur;
			}
		}
		return (dynamic_cast<TransactionNode&>(*newTemp));
}

/*Function: findLargest()
  Description: Returns a reference to a TransactionNode of the node with
			   the largest units.
*/
TransactionNode & BST::findLargest()
{
	Node *tempCur = this->mpRoot;
	Node *newTemp = nullptr;
	while (tempCur != nullptr) // traverse as much right as possible to find greatest value
	{
		tempCur = tempCur->getRight();
		if (tempCur != nullptr)
		{
			newTemp = tempCur;
		}
	}
	return (dynamic_cast<TransactionNode&>(*newTemp));
}

// Private Functions ---------------------------------------------------------------------------------------------

/*Function: destroyTree()
  Description: Visits each node of the tree in post order and
			   deletes it recursively.
*/
void BST::destroyTree(Node * const &pTree)
{
	if (pTree != nullptr)
	{
		destroyTree(pTree->getLeft());
		destroyTree(pTree->getRight());
		delete pTree;
	}
}

/*Function: insert()
  Description: Inserts a new data and units into a transaction node in the tree
			   in the correct spot.
*/
void BST::insert(Node * const &pTree, string const &newData, int const &newUnits)
{
	if (pTree != nullptr)
	{
		if ((dynamic_cast<TransactionNode*>(pTree))->getUnits() > newUnits) // left subtree
		{
			if (pTree->getLeft() != nullptr) // not found place to insert
			{
				insert(pTree->getLeft(), newData, newUnits);
			}
			else // found place to insert
			{
				pTree->setLeft(new TransactionNode(newData, newUnits));
			}
		}
		else if ((dynamic_cast<TransactionNode*>(pTree))->getUnits() < newUnits) // right subtree
		{
			if (pTree->getRight() != nullptr) // not found place to insert
			{
				insert(pTree->getRight(), newData, newUnits);
			}
			else // found place to insert
			{
				pTree->setRight(new TransactionNode(newData, newUnits));
			}
		}
		else // if they are equal
		{
			; // do nothing
		}
	}
	else // put data at root
	{
		this->setRoot(new TransactionNode(newData, newUnits));
	}
}

/*Function: inOrderTraversal()
  Description: Traverses through the tree recursively in order and
			   prints the contents of the TransactionNode.
*/
void BST::inOrderTraversal(Node * const &pTree)
{
	if (pTree != nullptr)
	{
		inOrderTraversal(pTree->getLeft());
		(dynamic_cast<TransactionNode*>(pTree))->printData();
		cout << endl;
		inOrderTraversal(pTree->getRight());
	}
}