//
//  lifo-stack-resizing-array.cpp
//  Copyright (c) 2017 Dylan Brown. All rights reserved.
//

// NOTES
// If you need this data structure in real code, reach for std::vector. Use the
// member functions vector::push_back and vector::pop_back instead of push and
// pop below. The tests run in main() are identical to the previous
// stack-resizing implementation.

#include <iostream>
#include <memory>

using std::make_shared;
using std::shared_ptr;

template <typename T> class Stack {
public:
  // Self-reflective functions on the status of the stack.
  bool is_empty() { return (N == 0); }
  int size() { return N; }

  void push(T item);
  T pop();

private:
  struct Node {
    T value;
    shared_ptr<Node> next = nullptr;
  };

  shared_ptr<Node> first = nullptr;
  int N = 0;
};

template <typename T> void Stack<T>::push(T item) {
  auto oldfirst = first;
  first = make_shared<Node>();
  first->value = item;
  first->next = oldfirst;
  N++;
}

template <typename T> T Stack<T>::pop() {
  T item = first->value;
  first = first->next;
  N--;
  return item;
}

int main() {
  using std::cout;
  using std::endl;

  // Create the stack with type `double`.
  auto lifo_stack = Stack<double>{};
  cout << "Created an empty LIFO stack for double type items, with a linked "
          "list implementation."
       << endl;

  // Fill the stack.
  lifo_stack.push(1.01);
  lifo_stack.push(2.02);
  lifo_stack.push(3.14);
  lifo_stack.push(4.04);
  cout << "Request status, the LIFO stack has size: " << lifo_stack.size()
       << endl;
  cout << "Request status, the LIFO stack is empty: "
       << (lifo_stack.is_empty() ? "true" : "false") << endl;

  // Call lifo_stack.pop(), until empty.
  while (!lifo_stack.is_empty()) {
    cout << "Popped an item from the stack: " << lifo_stack.pop() << endl;
  }

  // The final status of the list should be empty in each case.
  cout << "Request status, the LIFO stack has size: " << lifo_stack.size()
       << endl;
  cout << "Request status, the LIFO stack is empty: "
       << (lifo_stack.is_empty() ? "true" : "false") << endl;
}
