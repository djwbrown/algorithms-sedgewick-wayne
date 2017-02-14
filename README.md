#Algorithms, Sedgewick and Wayne

**Dylan Brown**  
djwbrown \_at\_ gmail  

## Introduction

The textbook _Algorithms, 4th Edition_ by Robert Sedgewick and Kevin Wayne covers a nice collection of fundamental data structures and algorithms (Index, p. 954). They provide implemented examples of each in Java along with some sample data for testing. I've decided to port each of them to C++ as a learning exercise. Where possible, I've tried to incorporate best practices for C++14 and later, with Scott Meyer's _Effective Modern C++_ as my guide.

## Get the data
The sample data is available at http://algs4.cs.princeton.edu/code/algs4-data.zip  
Please extract the files to this directory at the root-level of the repository. `./algs4-data/`

## List of algorithms

*Fundamentals*  
1.1 [Pushdown stack (resizing array)](blob/master/src/lifo-stack-resizing-array.cpp)  
1.2 Pushdown stack (linked-list)  
1.3 FIFO queue  
1.4 Bag  
1.5 Union-find  

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
