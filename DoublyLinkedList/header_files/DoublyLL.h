#ifndef DOUBLYLL_H
#define DOUBLYLL_H

#include "Node.h"
#include <optional>
#include <iostream>

class DoublyLL {
public:
    DoublyLL() = default;
    DoublyLL(const int value);

    void print_list()const;
    std::optional<const int> get_head()const;
    std::optional<const int> get_tail()const;
    const int get_length() const;

    void insert_tail(const int value);
    void insert_head(const int value);

    bool delete_tail();
    bool delete_head();

    std::optional<const int> get_node_value(const int index)const;
    bool set_node_value(const int index, const int value)const;

    bool insert_node(const int index, const int value);
    bool delete_node(const int index);

private:
    Node* get_node(const int index) const;

    int m_length = 0;
    Node* mp_headnode = nullptr;
    Node* mp_tailnode = nullptr;
};

#endif // !DOUBLYLL_H

