#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>
class LinkedList {
public:
	LinkedList() = default;
	LinkedList(const int value);
	~LinkedList();

	void insert_head(const int value);
	void insert_tail(const int value);
	void delete_head();
	void delete_tail();

	void print_list() const;

	// returns INT_MAX if there is no element in List
	[[nodiscard]] int get_head() const;
	[[nodiscard]] int get_tail() const;

	Node* get_index(const int index) const;
	bool set_index(const int index, const int value) const;
	bool insert_index(const int index, const int value);
	bool delete_index(const int index);

	bool reverse_list();

	
private:
	Node* p_headnode = nullptr;
	Node* p_tailnode = nullptr;
	int m_length = 0;
};
#endif // !LINKEDLIST_H

