#ifndef NODE_H
#define NODE_H

class Node {
public:
	Node(const int value) : node_value(value), p_nextnode(nullptr) {}

	~Node()
	{
		p_nextnode = nullptr;
		node_value = 0;
	}

	int node_value;
	Node* p_nextnode;
};
#endif // !NODE_H

