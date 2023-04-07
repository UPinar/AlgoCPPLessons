#include "LinkedList.h"

LinkedList::LinkedList(const int value)
{
	Node* p_newnode = new Node(value);

	p_headnode = p_newnode;
	p_tailnode = p_newnode;
	m_length = 1;
}

LinkedList::~LinkedList()
{
	Node* p_tempnode = p_headnode;
	while (p_headnode)
	{
		p_headnode = p_headnode->p_nextnode;
		delete p_tempnode;
		p_tempnode = p_headnode;
	}
}

void LinkedList::insert_head(const int value)
{
	Node* p_newnode = new Node(value);
	if (m_length == 0)
	{
		p_headnode = p_newnode;
		p_tailnode = p_newnode;
	}
	else {
		p_newnode->p_nextnode = p_headnode;
		p_headnode = p_newnode;
	}
	++m_length;
}

void LinkedList::insert_tail(const int value)
{
	Node* p_newnode = new Node(value);

	if (m_length == 0)
	{
		p_headnode = p_newnode;
		p_tailnode = p_newnode;
	}
	else {
		p_tailnode->p_nextnode = p_newnode;
		p_tailnode = p_newnode;
	}
	++m_length;
}

void LinkedList::delete_head()
{
	if (m_length == 0)
	{
		std::cout << "There is no element in list\n";
		return;
	}
	else if (m_length == 1)
	{
		delete p_headnode;
		p_headnode = nullptr;
		p_tailnode = nullptr;
	}
	else
	{
		Node* p_tempnode = p_headnode;
		p_headnode = p_headnode->p_nextnode;
		delete p_tempnode;
	}
	--m_length;
}

void LinkedList::delete_tail()
{
	if (m_length == 0)
	{
		std::cout << "There is no element in the list\n";
		return;
	}
	else if (m_length == 1)
	{
		delete p_tailnode;
		p_headnode = nullptr;
		p_tailnode = nullptr;
		--m_length;
	}
	else
	{ 
		delete p_tailnode;
		Node* p_tempnode = p_headnode;

		--m_length;
		for (int i = 1; i < m_length; ++i)
		{
			p_tempnode = p_tempnode->p_nextnode;
		}
		p_tailnode = p_tempnode;
		p_tailnode->p_nextnode = nullptr;
	}
}

void LinkedList::print_list() const
{
	if (m_length == 0)
		std::cout << "There is no element in the list\n";
	else
	{
		Node* p_tempnode = p_headnode;
		while (p_tempnode)
		{
			std::cout << p_tempnode->node_value << ' ';
			p_tempnode = p_tempnode->p_nextnode;
		}
		std::cout << '\n';
	}
}

int LinkedList::get_head() const
{
	if (!p_headnode)
		return INT_MAX;
	else
		return p_headnode->node_value;
}

int LinkedList::get_tail() const
{
	if (!p_tailnode)
		return INT_MAX;
	else
		return p_tailnode->node_value;
}

Node* LinkedList::get_index(const int index) const
{
	if (index >= m_length || index < 0)
		return nullptr;

	if (index == 0)
		return p_headnode;
	else if (index + 1 == m_length)
		return p_tailnode;
	else
	{
		// index 2 ise 3. element gonderilecek
		// 2 tur donecek.
		Node* p_tempnode = p_headnode;
		for (int i = 0; i < index; ++i)
		{
			p_tempnode = p_tempnode->p_nextnode;
		}
		return p_tempnode;
	}
}

bool LinkedList::set_index(const int index, const int value) const
{
	Node* p_tempnode = get_index(index);
	if (!p_tempnode)
		return false;
	else
	{
		p_tempnode->node_value = value;
		return true;
	}
}

bool LinkedList::insert_index(const int index, const int value)
{
	if (index < 0 || index > m_length)
		return false;
	else if (index == 0)
		insert_head(value);
	else if (index == m_length)
		insert_tail(value);
	else
	{
		Node* p_newnode = new Node(value);

		Node* p_nodebefore = get_index(index - 1);
		Node* p_nodeafter = get_index(index);

		p_nodebefore->p_nextnode = p_newnode;
		p_newnode->p_nextnode = p_nodeafter;
		++m_length;
	}	
	return true;
}

bool LinkedList::delete_index(const int index)
{
	if (index < 0 || index >= m_length)
		return false;
	else if (index == 0)
		delete_head();
	else if (index + 1 == m_length)
		delete_tail();
	else
	{
		Node* p_nodedelete = get_index(index);
		Node* p_nodebefore = get_index(index - 1);

		p_nodebefore->p_nextnode = p_nodedelete->p_nextnode;
		delete p_nodedelete;
		--m_length;
	}
	return true;
}

bool LinkedList::reverse_list()
{
	if (m_length <= 1)
		return false;
	else
	{
		Node* p_tempnode = p_headnode;
		p_headnode = p_tailnode;
		p_tailnode = p_tempnode;

		Node* p_nodebefore = nullptr;
		Node* p_nodeafter = p_tempnode->p_nextnode;;

		for (int i = 0; i < m_length; ++i)
		{
			p_nodeafter = p_tempnode->p_nextnode;
			p_tempnode->p_nextnode = p_nodebefore;
			p_nodebefore = p_tempnode;
			p_tempnode = p_nodeafter;
		}
		return true;
	}
}
