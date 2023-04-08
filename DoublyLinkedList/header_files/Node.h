#ifndef NODE_H
#define NODE_H

class Node {
public:
    Node(const int value) : node_value(value) {}
    friend class DoublyLL;
private:
    int node_value = 0;
    Node* next_node = nullptr;
    Node* prev_node = nullptr;
};

#endif // !NODE_H

