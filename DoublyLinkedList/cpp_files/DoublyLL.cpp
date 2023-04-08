#include "DoublyLL.h"

DoublyLL::DoublyLL(const int value)
{
    Node* new_node = new Node(value);
    mp_headnode = new_node;
    mp_tailnode = new_node;
    m_length = 1;
}

void DoublyLL::print_list() const
{
    std::string str{};
    if (m_length == 0)
        std::cout << "There is no element in the list.\n";
    else
    {
        std::cout << "List = ";
        Node* temp_node = mp_headnode;
        while (temp_node)
        {
            std::cout << temp_node->node_value << ' ';
            temp_node = temp_node->next_node;
        }
        std::cout << '\n';
    }
}

std::optional<const int> DoublyLL::get_head() const
{
    if (m_length == 0)
        return {};
    else
        return mp_headnode->node_value;
}

std::optional<const int> DoublyLL::get_tail() const
{
    if (m_length == 0)
        return {};
    else
        return mp_tailnode->node_value;
}

const int DoublyLL::get_length() const
{
    return m_length;
}

void DoublyLL::insert_tail(const int value)
{
    Node* new_node = new Node(value);

    if (m_length == 0)
    {
        mp_headnode = new_node;
        mp_tailnode = new_node;
    }
    else
    {
        mp_tailnode->next_node = new_node;
        new_node->prev_node = mp_tailnode;
        mp_tailnode = new_node;
    }
    ++m_length;
}

void DoublyLL::insert_head(const int value)
{
    if (m_length == 0)
        insert_tail(value);
    else
    {
        Node* new_node = new Node(value);

        new_node->next_node = mp_headnode;
        mp_headnode->prev_node = new_node;
        mp_headnode = new_node;
        ++m_length;
    }
}

bool DoublyLL::delete_tail()
{
    if (m_length == 0)
        return false;
    else if (m_length == 1)
    {
        delete mp_tailnode;
    }
    else
    {
        Node* temp_node;
        temp_node = mp_tailnode->prev_node;

        delete mp_tailnode;

        mp_tailnode = temp_node;
        mp_tailnode->next_node = nullptr;
    }
    --m_length;
    return true;
}

bool DoublyLL::delete_head()
{
    if (m_length == 0)
        return false;
    else if (m_length == 1)
        delete mp_headnode;
    else
    {
        Node* temp_node = mp_headnode->next_node;
        delete mp_headnode;
        mp_headnode = temp_node;
        mp_headnode->prev_node = nullptr;
    }
    --m_length;
    return true;
}

std::optional<const int> DoublyLL::get_node_value(const int index) const
{
    Node* node_tosend = get_node(index);

    if (node_tosend)
        return node_tosend->node_value;
    else
        return {};
}

bool DoublyLL::set_node_value(const int index, const int value) const
{
    Node* node_tosend = get_node(index);

    if (node_tosend)
    {
        node_tosend->node_value = value;
        return true;
    }
    else
        return false;
}

bool DoublyLL::insert_node(const int index, const int value)
{
    if (index < 0 || index > m_length)
        return false;
    else if (index == 0)
        insert_head(value);
    else if (index == m_length)
        insert_tail(value);
    else
    {
        Node* node_after = get_node(index);
        Node* node_before = node_after->prev_node;

        Node* new_node = new Node(value);
        node_before->next_node = new_node;
        new_node->prev_node = node_before;
        node_after->prev_node = new_node;
        new_node->next_node = node_after;

        ++m_length;
    }
    return true;
}

bool DoublyLL::delete_node(const int index)
{
    if (index < 0 || index >= m_length)
        return false;
    else if (index == 0)
        delete_head();
    else if (index == m_length - 1)
        delete_tail();
    else
    {
        Node* index_node = get_node(index);

        Node* node_before = index_node->prev_node;
        Node* node_after = index_node->next_node;

        node_before->next_node = node_after;
        node_after->prev_node = node_before;
        delete index_node;
        --m_length;
    }
    return true;
}

Node* DoublyLL::get_node(const int index) const
{
    if (index < 0 || index >= m_length)
        return nullptr;
    if (index == 0)
        return mp_headnode;
    else if (index == m_length - 1)
        return mp_tailnode;
    else
    {
        Node* temp_node;

        if (index < m_length / 2)
        {
            temp_node = mp_headnode;
            for (int i = 0; i < index; ++i)
            {
                temp_node = temp_node->next_node;
            }
        }
        else
        {
            temp_node = mp_tailnode;
            for (int i = m_length - 1; i > index; --i)
            {
                temp_node = temp_node->prev_node;
            }
        }
        return temp_node;
    }
}