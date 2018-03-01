#include "Node.h"


Node::Node(double entry)
	: entry_(entry), next_(NULL)
{

}

Node::Node(double entry, Node * next)
	: entry_(entry), next_(next)
{

}

Node::~Node()
{

}