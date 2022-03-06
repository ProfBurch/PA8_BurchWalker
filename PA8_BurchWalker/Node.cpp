
#include "Node.h"

 /**Constructors & Destructors**/
Node::Node() 
{ this->mpLeft = this->mpRight = nullptr; }

Node::Node(string& newData) 
{
	this->mpLeft = this->mpRight = nullptr;
	this->mData = newData;
}

/**Getters**/
const string Node::getData() 
{ return this->mData; }

Node*& Node::getLeft()
{ return this->mpLeft; }

Node*& Node::getRight() 
{ return this->mpRight; }

/**Non-Member Functions**/
ostream& operator<<(ostream& out, Node& node) 
{
	out << node.getData();
	return out;
}