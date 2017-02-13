//
//  lifo-stack-resizing-array.cpp
//  Copyright © 2017 Dylan Brown. All rights reserved.
//

#include <iostream>
#include <array>

using namespace std;

template<typename T> class ResizingArrayStack {
public:
    bool is_empty() { return ( N == 0 ); }
    int size() { return N; }
    
    void push(T item);
private:
    int max_size = 1;
    int N = 0;
    T* a = new T[1];

    void resize(int new_size);
};

template<typename T> void ResizingArrayStack<T>::push(T item)
{
    if (++N == max_size) { resize(2 * max_size); }
    a[N] = item;
}

template<typename T> void ResizingArrayStack<T>::resize(int new_size)
{
    max_size = new_size;
    T* temp = new T[max_size];
    for (int i = 0; i < N; i++) {
        temp[i] = a[i];
    }
    delete [] a;
    a = temp;
}

int main ()
{
    auto lifo_stack = ResizingArrayStack<double>{};
    cout << "Created an empty LIFO stack for `double`s, with a resizing array implementation." << endl;

    lifo_stack.push(3.14);
    lifo_stack.push(0.99);
    lifo_stack.push(1.01);
    cout << "Request status, the LIFO stack has size: " << lifo_stack.size() << endl;
    cout << "Request status, the LIFO stack is empty: " << (lifo_stack.is_empty() ? "true" : "false") << endl;
}
