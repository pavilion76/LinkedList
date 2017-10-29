#ifndef NODE_H_
#define NODE_H_

using namespace std;
template <class Type>

class Node{
public:
	Type data;
	Node *next;
	Node(Type value){
		data=value;
		next = NULL;
	}

};
#endif
