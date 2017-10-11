//
//  bag-multiset.cpp
//  Copyright © 2017 Dylan Brown. All rights reserved.
//

// NOTES
// For this bag data structure, the standard library provides std::multiset.
// Items are added one at a time and duplicates are permitted. Items cannot be
// accessed individually but are emptied all at once (and in an undefined order).

#include <iostream>
#include <memory>

using std::shared_ptr;
using std::make_shared;
using std::string;

template<typename T> class Bag {
public:
	// Self-reflective functions on the status of the multiset.
	bool is_empty() { return ( N == 0 ); }
	int size() { return N; }

	void add(T item);
	void empty_bag();

	string print_contents();

private:
	struct Node {
		T value;
		shared_ptr<Node> next = nullptr;
	};

	shared_ptr<Node> first = nullptr;
	int N = 0;
};

template<typename T> void Bag<T>::add(T item)
{
	auto oldfirst = first;
	first = make_shared<Node>();
	first->value = item;
	first->next = oldfirst;
	N++;
}

template<typename T> void Bag<T>::empty_bag()
{
	N = 0;
	first = nullptr;  // Clear the shared_ptr.
}

template<typename T> string Bag<T>::print_contents()
{
	// This seemed like a cleaner alternative to building an iterator on Bag. 
	// It's not as abstract and you can't use range-for, but it also seems
	// far less prone to bugs. See `lifo-stack-resizing-array.cpp` for an iterator.
	string str;
	str.reserve(size() * 5);
	while ( !is_empty() ) {
		str += " ";
		str += std::to_string(first->value);
		first = first->next;
		N--;
	}
	return str;
}

int main ()
{
	using std::cout;
	using std::endl;

	// Create the multiset with type `double`.
	auto test_multiset = Bag<double>{};
	cout << "Created an empty multiset for double type items, with a linked list implementation." << endl;
	
	// Fill the multiset.
	test_multiset.add(1.01);
	test_multiset.add(2.02);
	test_multiset.add(3.14);
	test_multiset.add(1.01);
	cout << "Request status, the multiset has size: " << test_multiset.size() << endl;
	cout << "Request status, the multiset is empty: " << (test_multiset.is_empty() ? "true" : "false") << endl;

	// Use the member functions to print the contents and empty the bag. Happens to be in LIFO order.
	cout << "Bag contains these items: {" << test_multiset.print_contents() << " }" << endl;
	test_multiset.empty_bag();

	// The final status of the list should be empty in each case.
	cout << "Request status, the multiset has size: " << test_multiset.size() << endl;
	cout << "Request status, the multiset is empty: " << (test_multiset.is_empty() ? "true" : "false") << endl;
}
