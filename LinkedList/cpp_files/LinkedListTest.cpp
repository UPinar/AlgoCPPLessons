#include "LinkedListTest.h"
#include "LinkedList.h"

void LinkedListTest::print_big_line()
{
	std::cout << "=============================================\n\n";
}

void LinkedListTest::print_small_line()
{
	std::cout << "---------------------------------------------\n";
}

void LinkedListTest::insert_head_test()
{
	std::cout << "INSERT HEAD TEST\n";
	LinkedList ll;

	for (int i = 10; i < 13; i++)
	{
		print_small_line();
		std::cout << i << " added to head\n";
		ll.insert_head(i);
		std::cout << "List = ";
		ll.print_list();
	}
	print_big_line();
}

void LinkedListTest::insert_tail_test()
{
	std::cout << "INSERT TAIL TEST\n";
	LinkedList ll;

	for (int i = 10; i < 13; i++)
	{
		print_small_line();
		std::cout << i << " added to tail\n";
		ll.insert_tail(i);
		std::cout << "List = ";
		ll.print_list();
	}
	print_big_line();
}

void LinkedListTest::delete_head_test()
{
	std::cout << "DELETE HEAD TEST\n";
	LinkedList ll;
	std::cout << "No elements in list\n";
	std::cout << "Head deleted\n";
	ll.delete_head();
	std::cout << "10, 11, 12, 13, 14, 15 added to list\n";

	for (int i = 10; i < 16; ++i)
	{
		ll.insert_tail(i);
	}
	std::cout << "List = ";
	ll.print_list();

	for (int i = 0; i < 3; ++i)
	{
		print_small_line();
		std::cout << "Head deleted\n";
		ll.delete_head();
		std::cout << "List = ";
		ll.print_list();
	}
	print_big_line();
}

void LinkedListTest::delete_tail_test()
{
	std::cout << "DELETE TAIL TEST\n";
	LinkedList ll;
	std::cout << "No elements in list\n";
	std::cout << "Head deleted\n";
	ll.delete_tail();
	print_small_line();
	
	std::cout << "10, 11, 12, 13, 14, 15 added to list\n";
	for (int i = 10; i < 16; ++i)
	{
		ll.insert_tail(i);
	}
	std::cout << "List = ";
	ll.print_list();

	for (int i = 0; i < 3; ++i)
	{
		print_small_line();
		std::cout << "Tail deleted\n";
		ll.delete_tail();
		std::cout << "List = ";
		ll.print_list();
		
	}
	print_big_line();
}

void LinkedListTest::get_head_test()
{
	std::cout << "GET HEAD TEST\n";
	LinkedList ll;
	std::cout << "No elements in list\n";
	std::cout << "get_head called\n";
	int headVal = ll.get_head();
	std::cout << "Head = " << headVal << '\n';
	print_small_line();

	std::cout << "10 added to list\n";
	ll.insert_head(10);
	std::cout << "List = ";
	ll.print_list();
	std::cout << "get_head called\n";
	headVal = ll.get_head();
	std::cout << "Head = " << headVal << '\n';
	print_big_line();
}

void LinkedListTest::get_tail_test()
{
	std::cout << "GET TAIL TEST\n";
	LinkedList ll;
	std::cout << "No elements in list\n";
	std::cout << "get_tail called\n";
	int headVal = ll.get_tail();
	std::cout << "Tail = " << headVal << '\n';

	for (int i = 10; i < 13; i++)
	{
		print_small_line();
		std::cout << i <<" added to list\n";
		ll.insert_head(i);
		std::cout << "List = ";
		ll.print_list();
		std::cout << "get_tail called\n";
		headVal = ll.get_tail();
		std::cout << "Tail = " << headVal << '\n';
	}
	print_big_line();
}

void LinkedListTest::get_index_test()
{
	std::cout << "GET INDEX TEST\n";
	LinkedList ll;
	std::cout << "10, 11, 12, 13, 14, 15 added to list\n";
	for (int i = 10; i < 16; ++i)
	{
		ll.insert_tail(i);
	}
	std::cout << "List = ";
	ll.print_list();

	for (int i = -1; i < 7; ++i)
	{
		print_small_line();
		std::cout << i << " index was called\n";
		if (!ll.get_index(i))
			std::cout << "returned nullptr\n";
		else
			std::cout << "Value is " << ll.get_index(i)->node_value << '\n';
	}
	print_big_line();
}

void LinkedListTest::set_index_test()
{
	std::cout << "SET INDEX TEST\n";
	LinkedList ll;
	std::cout << "10, 11, 12, 13, 14, 15 added to list\n";
	for (int i = 10; i < 16; ++i)
	{
		ll.insert_tail(i);
	}
	std::cout << "List = ";
	ll.print_list();

	for (int i = -1; i < 7; ++i)
	{
		print_small_line();
		std::cout << i << " index set value 99 called\n";
		if (!ll.set_index(i,99))
			std::cout << "returned false\n";
		else
		{
			std::cout << "List = ";
			ll.print_list();
		}	
	}
	print_big_line();
}

void LinkedListTest::insert_index_test()
{
	std::cout << "INSERT INDEX TEST\n";
	LinkedList ll;
	std::cout << "10, 11 added to list\n";
	for (int i = 10; i < 12; ++i)
	{
		ll.insert_tail(i);
	}
	std::cout << "List = ";
	ll.print_list();


	for (int i = -2; i < 7; i += 2)
	{
		print_small_line();
		std::cout << "to index " << i << ", 99 inserted\n";

		if (!ll.insert_index(i, 99))
			std::cout << "returned false\n";
		else
		{
			std::cout << "List = ";
			ll.print_list();
		}
	}

	print_big_line();
}

void LinkedListTest::delete_index_test()
{
	std::cout << "DELETE INDEX TEST\n";
	LinkedList ll;
	std::cout << "10, 11, 12, 13 added to list\n";
	for (int i = 10; i < 14; ++i)
	{
		ll.insert_tail(i);
	}
	std::cout << "List = ";
	ll.print_list();

	for (int i = -2; i < 6; i += 2)
	{
		print_small_line();
		std::cout << "index " << i << " deleted\n";

		if (!ll.delete_index(i))
			std::cout << "returned false\n";
		else
		{
			std::cout << "List = ";
			ll.print_list();
		}
	}
	print_big_line();
}

void LinkedListTest::reverse_list_test()
{
	std::cout << "REVERSE LIST TEST\n";

	LinkedList ll;
	std::cout << "List = ";
	ll.print_list();
	std::cout << "reversed tried\n";
	if (bool b = ll.reverse_list(); !b)
		std::cout << "reverse failed return false\n";

	for (int i = 10; i < 14; ++i)
	{
		print_small_line();
		std::cout << i << " added to list\n";
		ll.insert_tail(i);
		std::cout << "List = ";
		ll.print_list();
		std::cout << "reversed tried\n";
		if (!ll.reverse_list())
			std::cout << "reverse failed return false\n";
		else
		{
			std::cout << "List = ";
			ll.print_list();
		}
	}
	print_big_line();
}
