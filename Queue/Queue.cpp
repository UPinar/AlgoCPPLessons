#include <iostream>
#include <initializer_list>
#include <optional>

class Node {
public:
	Node(int value) : m_value(value), mp_nextnode(nullptr) {}
private:
	int m_value;
	Node* mp_nextnode;
	friend class Queue;
};

class Queue {
public:
	Queue() = default;

	Queue(int value)
	{
		Node* new_node = new Node(value);
		mp_firstnode = new_node;
		mp_lastnode = new_node;
		++m_length;
	}

	Queue(std::initializer_list<int> queue_list)
	{
		Node* temp_node = nullptr;
		for (int elem : queue_list)
		{
			Node* new_node = new Node(elem);

			new_node->mp_nextnode = temp_node;
			if (m_length == 0)
			{
				mp_firstnode = new_node;
				mp_lastnode  = new_node;
			}
			else
				mp_lastnode = new_node;
			
			++m_length;
			temp_node = new_node;
		}
	}

	std::optional<int> get_first()
	{
		if (m_length != 0)
			return mp_firstnode->m_value;
		else
			return {};
	}

	std::optional<int> get_last()
	{
		if (m_length != 0)
			return mp_lastnode->m_value;
		else
			return {};
	}

	void print_queue() const
	{
		Node* temp_node = mp_lastnode;	
		std::cout << "Queue = ";
		while (temp_node)
		{
			std::cout << temp_node->m_value << ' ';
			temp_node = temp_node->mp_nextnode;
		}
		std::cout << '\n';
	}

	void add_last(int value)	// O(1)
	{
		Node* new_node = new Node(value);
		
		if (m_length == 0)
		{
			mp_firstnode = new_node;
			mp_lastnode = new_node;
		}
		else
		{
			new_node->mp_nextnode = mp_lastnode;
			mp_lastnode = new_node;
		}
		++m_length;
	}

	void add_first(int value)	// O(1)
	{
		Node* new_node = new Node(value);

		if (m_length == 0)
		{
			mp_firstnode = new_node;
			mp_lastnode = new_node;
		}
		else
		{
			mp_firstnode->mp_nextnode = new_node;
			mp_firstnode = new_node;
		}
		++m_length;
	}

	void remove_last()	// O(1)
	{
		if (m_length == 0)
			return;
		else if (m_length == 1)
			delete mp_firstnode;
		else
		{
			Node* temp_node = mp_lastnode->mp_nextnode;
			delete mp_lastnode;
			mp_lastnode = temp_node;
		}
		--m_length;
	}

	void remove_first() // O(n)
	{
		if (m_length == 0)
			return;
		else if (m_length == 1)
			delete mp_firstnode;
		else
		{
			Node* tempnode = mp_lastnode;

			while (tempnode->mp_nextnode != mp_firstnode)
			{
				tempnode = tempnode->mp_nextnode;
			}
			tempnode->mp_nextnode = nullptr;
			delete mp_firstnode;
			mp_firstnode = tempnode;
		}
		--m_length;
	}

private:
	Node* mp_firstnode = nullptr;
	Node* mp_lastnode = nullptr;
	int m_length = 0;
};

int main()
{
	Queue qlist = { 10,12,14,16,18 };

	std::cout << "First = " << qlist.get_first().value() << '\n';
	std::cout << "Last = " << qlist.get_last().value() << '\n';
}