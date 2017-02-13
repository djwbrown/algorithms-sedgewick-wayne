//
//  lifo-stack-resizing-array.cpp
//  Copyright © 2017 Dylan Brown. All rights reserved.
//

#include <iostream>

using namespace std;

template<typename T> class ResizingArrayStack {
public:
	bool is_empty() { return ( N == 0 ); }
private:
  int N = 0;
  void resize(int max) {
    N = max * 2;
  }
};

int main ()
{
  auto lifo_stack = ResizingArrayStack<double>{};
  cout << "Test if empty: " << lifo_stack.is_empty() << endl;
}
