
#include "BST.h"

 /**Constructors & Destructors**/
BST::BST() 
{ this->mpRoot = nullptr; }

BST::~BST() 
{ destroyTree(this->mpRoot); }

void BST::destroyTree(Node*& pTree) 
{
	if (pTree != nullptr) // If not a leaf, delete.
	{ 
		destroyTree(pTree->getLeft());
		destroyTree(pTree->getRight());
		delete pTree;
	}
}

/**Setters**/
void BST::setRoot(Node* newNode) 
{ this->mpRoot = newNode; }

void BST::insert(string& newProductData, int& newUnitData)
{
	insertHelper(mpRoot, newProductData, newUnitData);  // call recursive helper
}

void BST::insertHelper(Node*& pTree, string& newProductData, int& newUnitData) 
{
	if (pTree == nullptr) // If a leaf has been reached, insert.
	{
		pTree = new TransactionNode(newProductData, newUnitData);
	}
	else if ((dynamic_cast<TransactionNode*> (pTree))->getUnits() > newUnitData) // go left
	{
		insertHelper(pTree->getLeft(), newProductData, newUnitData);
	} 
	else  // go right
	{
		insertHelper(pTree->getRight(), newProductData, newUnitData);
	}
}

/**Getters**/
bool BST::isEmpty() 
{ return (this->mpRoot == nullptr); }

Node* BST::getRoot() 
{ return this->mpRoot; }

void BST::inOrderTraversal() const 
{ inOrderTraversalHelper(this->mpRoot, 0); }

void BST::inOrderTraversalHelper(Node* pTree, int indent) const 
{
	if (pTree != nullptr) 
	{
		inOrderTraversalHelper(pTree->getLeft(), indent + 4);

		if (indent)
		{
			cout << std::setw(indent) << " ";
		}

		pTree->printData();
		cout << endl << " ";

		inOrderTraversalHelper(pTree->getRight(), indent + 4);
	}
	cout << endl;
}

// Precondition: Tree is not empty.
TransactionNode& BST::findSmallest() 
{
	Node* transactionNode = mpRoot;

	while (transactionNode->getLeft() != nullptr)
	{
		transactionNode = transactionNode->getLeft();
	}

	return *(dynamic_cast<TransactionNode*> (transactionNode));
}

// Precondition: Tree is not empty.
TransactionNode& BST::findLargest() 
{
	Node* transactionNode = mpRoot;

	while (transactionNode->getRight() != nullptr)
	{
		transactionNode = transactionNode->getRight();
	}

	return *(dynamic_cast<TransactionNode*> (transactionNode));
}