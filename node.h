#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>
using std::cout;
using std::endl;


class Node
{
public:
	double entry_;
	Node * next_;

public:

	explicit Node(double entry);

	Node(double entry, Node * next);

	~Node();

private:
	Node();
	Node(const Node &);
};

#endif
