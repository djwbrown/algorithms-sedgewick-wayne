//
//  lifo-stack-resizing-array.cpp
//  Copyright © 2017 Dylan Brown. All rights reserved.
//

#include <iostream>

using namespace std;

template<typename T> class ResizingArrayStack {
public:
    // Self-reflective functions on the status of the stack.
    bool is_empty() { return ( N == 0 ); }
    int size() { return N; }
    
    void push(T item);
    T pop();

    T* begin() { return &array_ptr[0]; }
    T* end() { return &array_ptr[N]; }

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

    // Here we're iterating forward through the array, with an unused variable `i`.
    // It would be nice performance-wise to iterate in reverse without calling pop(), and without triggering a resize.
    for ( auto& i : lifo_stack ) {
        cout << "Current loop iteration has i = " << i << endl;
    }
    // // Alternatively, call lifo_stack.pop(), N times.
    // cout << "Popped an item from the stack: " << lifo_stack.pop() << endl;
    // cout << "Popped an item from the stack: " << lifo_stack.pop() << endl;
    // cout << "Popped an item from the stack: " << lifo_stack.pop() << endl;
    // cout << "Popped an item from the stack: " << lifo_stack.pop() << endl;
    
    cout << "Request status, the LIFO stack has size: " << lifo_stack.size() << endl;
    cout << "Request status, the LIFO stack is empty: " << (lifo_stack.is_empty() ? "true" : "false") << endl;
}
