# Algorithms, Sedgewick and Wayne

**Dylan Brown**  
djwbrown \_at\_ gmail  

## Introduction

_Algorithms, 4th Edition_ by Robert Sedgewick and Kevin Wayne covers a nice collection of data structures and algorithms. The authors provide examples implemented in Java along with some sample data for testing.
> Our original goal for [this book](http://algs4.cs.princeton.edu/code/) was to cover the _50 algorithms that every programmer should know_.

Here I've ported each one to C++ as a learning exercise. I've tried to incorporate best practices for C++17 and later, with the [C++ Core Guidelines](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines) and Scott Meyer's _Effective Modern C++_ as my guide.

## Get the data
The sample data is available at http://algs4.cs.princeton.edu/code/algs4-data.zip  
Please extract the files to this directory at the root-level of the repository. `./algs4-data/`

## Build and run
```
mkdir build
cd build
cmake ..
make

# Run any algorithm.
./depth-first-search
```

## List of algorithms

*Fundamentals*  
1.1 [Pushdown stack (resizing array)](src/lifo-stack-resizing-array.cpp)  
1.2 [Pushdown stack (linked-list)](src/lifo-stack-linked-list.cpp)  
1.3 [FIFO queue](src/fifo-queue.cpp)  
1.4 [Bag (Multiset)](src/bag-multiset.cpp)  
1.5 [Union-find (Disjoint-set)](src/union-find.cpp)  

*Sorting*  
2.1 Selection sort  
2.2 Insertion sort  
2.3 Shellsort  
2.4 Top-down and bottom-up mergesort  
2.5 Quicksort, and quicksort with 3-way partitioning  

*Symbol Tables*  
3.1 Sequential search  
3.2 Binary search  
3.3 Binary search tree (BST)  
3.4 Red-black BST  
3.5 Hashing with separate chaining  
3.6 Hashing with linear probing  

*Graphs*  
4.1 Depth-first search  
4.2 Breadth-first search  
4.3 Connected components  
4.4 Reachability  
4.5 Topological sort  
4.6 Strong components (Kosaraju-Sharir)  
4.7 Minimum spanning tree (Prim)  
4.8 Minimum spanning tree (Kruskal)  
4.9 Shortest paths (Djikstra)  
4.10 Shortest paths in DAGs  
4.11 Shortest paths (Bellman-Ford)  

*Strings*  
5.1 LSD string sort  
5.2 MSD string sort  
5.3 Three-way string quicksort  
5.4 Trie symbol table  
5.5 TST symbol table  
5.6 Substring search (Knuth-Morris-Pratt)  
5.6 Substring search (Boyer-Moore)  
5.6 Substring search (Rabin-Karp)  
5.9 Regular expression pattern matching  
5.10 Huffman compression-expansion  
5.11 LZW compression-expansion  
