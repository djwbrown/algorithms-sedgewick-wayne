//
//  fifo-queue.cpp
//  Copyright (c) 2017 Dylan Brown. All rights reserved.
//

// NOTES
// Once again, users of this class would be better served by the standard
// library with std::deque (double-ended queue). Unlike std::vector, insertions
// and deletions at either end of a std::deque are constant-time O(1). Use the
// push_front() and pop_back() member functions.

#include <iostream>
#include <memory>

using std::make_shared;
using std::shared_ptr;

template <typename T> class Queue {
public:
  // Self-reflective functions on the status of the queue.
  bool is_empty() { return (N == 0); }
  int size() { return N; }

  void enqueue(T item);
  T dequeue();

private:
  struct Node {
    T value;
    shared_ptr<Node> next = nullptr;
  };

  shared_ptr<Node> first = nullptr;
  shared_ptr<Node> last = nullptr;
  int N = 0;
};

template <typename T> void Queue<T>::enqueue(T item) {
  auto oldlast = last;
  last = make_shared<Node>();
  last->value = item;
  last->next = nullptr;

  if (is_empty()) {
    first = last;
  } else {
    oldlast->next = last;
  }
  N++;
}

template <typename T> T Queue<T>::dequeue() {
  auto item = first->value;
  first = first->next;
  N--;
  if (is_empty())
    last = nullptr;
  return item;
}

int main() {
  using std::cout;
  using std::endl;

  // Create a queue with type `double`.
  auto fifo_queue = Queue<double>{};
  cout << "Created an empty FIFO queue for double type items, with a linked "
          "list implementation."
       << endl;

  // Fill the queue.
  fifo_queue.enqueue(1.01);
  fifo_queue.enqueue(2.02);
  fifo_queue.enqueue(3.14);
  fifo_queue.enqueue(4.04);
  cout << "Request status, the FIFO queue has size: " << fifo_queue.size()
       << endl;
  cout << "Request status, the FIFO queue is empty: "
       << (fifo_queue.is_empty() ? "true" : "false") << endl;

  // Call fifo_queue.dequeue(), until empty.
  while (!fifo_queue.is_empty()) {
    cout << "dequeued an item from the queue: " << fifo_queue.dequeue() << endl;
  }

  // The final status of the list should be empty in each case.
  cout << "Request status, the FIFO queue has size: " << fifo_queue.size()
       << endl;
  cout << "Request status, the FIFO queue is empty: "
       << (fifo_queue.is_empty() ? "true" : "false") << endl;
}
