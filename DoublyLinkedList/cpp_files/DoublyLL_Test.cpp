#include "DoublyLL_Test.h"


void DoublyLL_Test::print_big_line()
{
	std::cout << "=============================================\n\n";
}

void DoublyLL_Test::print_small_line()
{
	std::cout << "---------------------------------------------\n";
}


void DoublyLL_Test::get_head_test()
{
	std::cout << "GET HEAD TEST \n";
	print_small_line();
	DoublyLL ll;
	ll.print_list();
	std::cout << "get_head() called\n";
	if (ll.get_head().has_value())
		std::cout << ll.get_head().value() << '\n';
	else
		std::cout << "No value in the head\n";

	for (int i = 10; i < 12; ++i)
	{
		print_small_line();
		std::cout << i << " inserted\n";
		ll.insert_head(i);
		ll.print_list();
		std::cout << "get_head() called\n";
		if (ll.get_head().has_value())
			std::cout << ll.get_head().value() << '\n';
		else
			std::cout << "No value in the head\n";
	}
	print_big_line();
}

void DoublyLL_Test::get_tail_test() 
{
	std::cout << "GET TAIL TEST \n";
	print_small_line();
	DoublyLL ll;
	ll.print_list();
	std::cout << "get_tail() called\n";
	if (ll.get_tail().has_value())
		std::cout << ll.get_tail().value() << '\n';
	else
		std::cout << "No value in the tail\n";

	for (int i = 10; i < 12; ++i)
	{
		print_small_line();
		std::cout << i << " inserted\n";
		ll.insert_head(i);
		ll.print_list();
		std::cout << "get_tail() called\n";
		if (ll.get_tail().has_value())
			std::cout << ll.get_tail().value() << '\n';
		else
			std::cout << "No value in the tail\n";
	}
	print_big_line();
}
void DoublyLL_Test::insert_tail_test() 
{
	std::cout << "INSERT TAIL TEST \n";
	print_small_line();
	DoublyLL ll;
	ll.print_list();

	for (int i = 10; i < 16; ++i)
	{
		print_small_line();
		std::cout << i << " inserted to tail\n";
		ll.insert_tail(i);
		ll.print_list();
	}
	print_big_line();
}
void DoublyLL_Test::insert_head_test() 
{
	std::cout << "INSERT HEAD TEST \n";
	print_small_line();
	DoublyLL ll;
	ll.print_list();

	for (int i = 10; i < 16; ++i)
	{
		print_small_line();
		std::cout << i << " inserted to head\n";
		ll.insert_head(i);
		ll.print_list();
	}
	print_big_line();
}
void DoublyLL_Test::delete_tail_test() 
{
	std::cout << "DELETE TAIL TEST \n";
	print_small_line();
	DoublyLL ll;
	for (int i = 10; i < 16; ++i)
	{
		ll.insert_head(i);
	}
	ll.print_list();

	for (int i = 10; i < 16; ++i)
	{
		print_small_line();
		std::cout << i << " deleted tail\n";
		ll.delete_tail();
		ll.print_list();
	}
	print_big_line();
}
void DoublyLL_Test::delete_head_test() 
{
	std::cout << "DELETE HEAD TEST \n";
	print_small_line();
	DoublyLL ll;
	for (int i = 10; i < 16; ++i)
	{
		ll.insert_tail(i);
	}
	ll.print_list();

	for (int i = 10; i < 16; ++i)
	{
		print_small_line();
		std::cout << i << " deleted head\n";
		ll.delete_head();
		ll.print_list();
	}
	print_big_line();
}
void DoublyLL_Test::get_node_value_test() 
{
	std::cout << "GET NODE VALUE TEST \n";
	print_small_line();
	DoublyLL ll;
	for (int i = 10; i < 16; ++i)
	{
		ll.insert_tail(i);
	}
	ll.print_list();
	
	for (int i = -2; i < 8; i += 2)
	{
		print_small_line();
		std::cout << "Tried to get " << i << " index value\n";
		if (ll.get_node_value(i).has_value())
			std::cout << ll.get_node_value(i).value() << '\n';
		else
			std::cout << "There is no index\n";
		ll.print_list();
	}
	print_big_line();
}
void DoublyLL_Test::set_node_value_test() 
{
	std::cout << "SET NODE VALUE TEST \n";
	print_small_line();
	DoublyLL ll;
	for (int i = 10; i < 14; ++i)
	{
		ll.insert_tail(i);
	}
	ll.print_list();

	for (int i = -1; i < 5; ++i)
	{
		print_small_line();
		std::cout << "Tried to set 99 to " << i << " index \n";
		if (ll.set_node_value(i, 99))
			std::cout << "Inserted\n";
		else
			std::cout << "Can not insert to that index\n";
		ll.print_list();
	}
	print_big_line();
}
void DoublyLL_Test::insert_node_test() 
{
	std::cout << "INSERT NODE TEST \n";
	print_small_line();
	DoublyLL ll;
	for (int i = 10; i < 14; ++i)
	{
		ll.insert_tail(i);
	}
	ll.print_list();

	for (int i = -1; i < 9; i+=2)
	{
		print_small_line();
		std::cout << "Tried to insert 99 to " << i << " index \n";
		if (ll.insert_node(i, 99))
			std::cout << "Inserted\n";
		else
			std::cout << "Can not insert to that index\n";
		ll.print_list();
	}
	print_big_line();
}
void DoublyLL_Test::delete_node_test() 
{
	std::cout << "DELETE NODE TEST \n";
	print_small_line();
	DoublyLL ll;
	for (int i = 10; i < 16; ++i)
	{
		ll.insert_tail(i);
	}
	ll.print_list();

	for (int i = -1; i < 4; ++i)
	{
		print_small_line();
		std::cout << "Delete node in " << i << " index \n";
		if (ll.delete_node(i))
			std::cout << "Deleted\n";
		else
			std::cout << "Can not delete that index\n";
		ll.print_list();
	}
	print_big_line();
}



