#pragma once

#include "TransactionNode.h"

class BST 
{
public:
	/**Constructors & Destructors**/
	BST();
	~BST();

	/**Setters**/
	void setRoot(Node* newNode);
	void insert(string& newProductData, int& newUnitData);

	/**Getters**/
	bool isEmpty();
	Node* getRoot();
	void inOrderTraversal() const; // some print code borrowed from StackOverflow
	TransactionNode& findSmallest();
	TransactionNode& findLargest();

private:
	Node* mpRoot;

	/**Destructor**/
	void destroyTree(Node*& pTree);

	/**Setters**/
	void insertHelper(Node*& pTree, string& newProductData, int& newUnitData);

	/**Getters**/
	void inOrderTraversalHelper(Node* pTree, int indent) const;
};
