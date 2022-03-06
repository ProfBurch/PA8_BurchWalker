#pragma once

#include "TheEverythingHeader.h";
#include "Node.h"

class TransactionNode : public Node 
{
public:

	/**Constructors & Destructors**/
	TransactionNode(string newProduct, int newUnits);
	~TransactionNode() { }

	/**Getters**/
	int getUnits();
	void printData();

	/**Setters**/
	void setUnits(int newUnits);
private:

	/**Private data**/
	int mUnits;
};
