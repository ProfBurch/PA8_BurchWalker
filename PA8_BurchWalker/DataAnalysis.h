#pragma once

#include "BST.h"

class DataAnalysis 
{
public:

	/**Constructors & Destructors**/
	DataAnalysis();
	~DataAnalysis() {}

	/**Misc**/
	void runAnalysis();
private:

	/**Private data**/
	BST mTreeSold;
	BST mTreePurchased;
	ifstream mCsvStream;

	/**Setters**/
	void openStream();
	bool parseLineFromStream(string* transactionField, int* unitField, string* typeField);
	void insertInTrees(string transaction, int unit, string type);
	void readAndDisplayFile(); // calls parseLineFromStream and insertInTrees

	/**Getter**/
	void displayTrends();
};
