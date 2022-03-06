#pragma once

#include "TheEverythingHeader.h"

class Node 
{
public:
	/**Constructors & Destructors**/
	Node();
	Node(string& newData);
	~Node() {}

	/**Getters**/
	const string getData();
	Node*& getLeft();
	Node*& getRight();

	// Pure Virtual function makes class `BSTNode` abstract
	virtual void printData() = 0;
protected:
	/**Private data**/
	string mData;
	Node* mpLeft;
	Node* mpRight;
};

/**Non-Member Functions**/
ostream& operator<<(ostream& out, Node& node);
