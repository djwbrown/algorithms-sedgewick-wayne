//
//  lifo-stack-resizing-array.cpp
//  Copyright (c) 2017 Dylan Brown. All rights reserved.
//

// NOTES
// The authors' inclusion of an iterator on the stack is a bit unconventional. Typically one would just
// call pop after checking that the stack is not empty. However, it allowed me to gain some experience
// with std::iterator and there _could_ be a performance gain in cases where you want to dump the contents
// of the stack (still in LIFO order) all at once without cost of a rezise or repeated underflow check.

#include <iostream>
#include <iterator>

template<typename T> class ResizingArrayStack {
public:
	// Self-reflective functions on the status of the stack.
	bool is_empty() { return ( N == 0 ); }
	int size() { return N; }
	
	void push(T item);
	T pop();

	//----- Begin reversed iteration section -----//
	// Please see the example here, (http://en.cppreference.com/w/cpp/iterator/iterator).
	// Member typedefs inherit from std::iterator.
	class stackIterator: public std::iterator<
						std::input_iterator_tag,   // iterator_category
						T,                         // value_type
						T,                         // difference_type
						const T*,                  // pointer
						T                          // reference
						>{
		int index = 0;
		T* it_ptr = nullptr;
	public:
		stackIterator(int _index = 0, T* _it_ptr = nullptr) { index = _index; it_ptr = _it_ptr; }
		// Prefix ++, equal, unequal, and dereference operators are the minimum required for range based for-loops.
		stackIterator& operator++() { --index; return *this; }  // Here is where we reverse the sequence.
		bool operator==(stackIterator other) { return index == other.index; }
		bool operator!=(stackIterator other) { return !( *this == other ); }
		T operator*() { return it_ptr[index-1]; }
	};

	stackIterator begin() { return stackIterator(N, array_ptr); }
	stackIterator end() {
		N = 0;  // 'Empty' the array.
		max_size = 1;  // Don't waste time calling resize() now. 
		return stackIterator(0, array_ptr);
	}
	//----- End reversed iteration section -----//

	~ResizingArrayStack() {
		// Style note for 'modern' C++: prefer unique_ptr to new/delete operators.
		delete [] array_ptr;
	}

private:
	// Allocate space for a traditional array on the heap.
	T* array_ptr = new T[1];
	// Keep track of the space allocated for the array, max_size * sizeof(T).
	int max_size = 1;
	// Keep track of the current number of items on the stack.
	int N = 0;

	void resize(int new_size);
};

template<typename T> void ResizingArrayStack<T>::push(T item)
{
	if (N == max_size) { resize(2 * max_size); }
	// Push to the stack and increment the current count of items.
	array_ptr[N++] = item;
}

template<typename T> T ResizingArrayStack<T>::pop()
{
	// Warning: calling pop() on an empty ResizingArrayStack is UNDEFINED.
	// Remember that max index is N-1, so prefix decrement to pop from the stack.
	T item = array_ptr[--N];
	// Shrink the array if needed.
	if ( N > 0 && N == (max_size / 4) ) { resize(max_size / 2); }
	return item;
}

template<typename T> void ResizingArrayStack<T>::resize(int new_size)
{
	max_size = new_size;
	// Allocate a replacement array with space adequate for the stack.
	T* replacement = new T[max_size];
	// Copy each element into the replacement array.
	for (int i = 0; i < N; i++) {
		replacement[i] = array_ptr[i];
	}
	// Free the memory associated with the old array.
	delete [] array_ptr;
	// Reset the pointer to the newly resized array.
	array_ptr = replacement;
}

int main ()
{
	using std::cout;
	using std::endl;

	// Create the stack with type `double`.
	auto lifo_stack = ResizingArrayStack<double>{};
	cout << "Created an empty LIFO stack for double type items, with a resizing array implementation." << endl;
	
	// Fill the stack.
	lifo_stack.push(1.01);
	lifo_stack.push(2.02);
	lifo_stack.push(3.14);
	lifo_stack.push(4.04);
	cout << "Request status, the LIFO stack has size: " << lifo_stack.size() << endl;
	cout << "Request status, the LIFO stack is empty: " << (lifo_stack.is_empty() ? "true" : "false") << endl;

	// It's nice performance-wise to iterate in reverse without calling pop() or triggering a resize.
	for ( auto item : lifo_stack) {
		cout << "Current loop iteration has item = " << item << endl;
	}

	// // Alternatively, call lifo_stack.pop(), N times.
	// cout << "Popped an item from the stack: " << lifo_stack.pop() << endl;
	// cout << "Popped an item from the stack: " << lifo_stack.pop() << endl;
	// cout << "Popped an item from the stack: " << lifo_stack.pop() << endl;
	// cout << "Popped an item from the stack: " << lifo_stack.pop() << endl;

	// The final status of the array should be empty in each case.
	cout << "Request status, the LIFO stack has size: " << lifo_stack.size() << endl;
	cout << "Request status, the LIFO stack is empty: " << (lifo_stack.is_empty() ? "true" : "false") << endl;
}
