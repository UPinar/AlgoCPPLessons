#include <iostream>
#include <optional>
#include <initializer_list>

class Node {
public:
	Node(int value) : node_value(value), next_ptr(nullptr) {}
private:
	int node_value;
	Node* next_ptr;
	friend class Stack;
};

class Stack {
public:
	Stack()  = default;
	Stack(int value)
	{
		Node* new_node = new Node(value);
		mp_topnode = new_node;
		m_height = 1;
	}

	Stack(std::initializer_list<int> list)
	{
		for (int elem : list)
		{
			push(elem);
		}
	}

	std::optional<int> get_top_value() const
	{
		if (m_height != 0)
			return mp_topnode->node_value;
		else
			return {};
	}

	int get_height() const
	{
		return m_height;
	}

	void print_stack() const
	{
		Node* temp_node = mp_topnode;
		std::cout << "Stack = ";
		while (temp_node)
		{
			std::cout << temp_node->node_value << ' ';
			temp_node = temp_node->next_ptr;
		}
		std::cout << '\n';
	}

	void push(int value)
	{
		Node* new_node = new Node(value);

		if (m_height == 0)
			mp_topnode = new_node;
		else
		{
			new_node->next_ptr = mp_topnode;
			mp_topnode = new_node;
		}
		++m_height;
	}

	void pop()
	{
		if (m_height == 0)
			return;
		else
		{
			Node* temp_node = mp_topnode->next_ptr;
			delete mp_topnode;
			mp_topnode = temp_node;
			--m_height;
		}
	}
private:
	Node* mp_topnode = nullptr;
	int m_height = 0;
};

int main()
{

}

