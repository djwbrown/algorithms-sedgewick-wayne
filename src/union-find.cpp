//
//  union-find.cpp
//  Copyright © 2017 Dylan Brown. All rights reserved.
//

// NOTES
// Given a list of connected vertices, where the transitive property applies (a--b ; b--c ==> a--c),
// determine the total number of connected components in the union-find data structure.
// The implementation here is the 'weighted quick-union' algorithm, with performance O(lg n).

#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <string>
#include <utility>
#include <cstdlib>

using std::vector;
using std::pair;
using std::get;

class WeightedQuickUnionUF {
public:
	WeightedQuickUnionUF (int N) {
		// Constructor creates a vector with each index representing the vertex
		// and the value representing the root of that connected component.
		count = N;
		id.reserve(N);
		sz.reserve(N);

		for (int i = 0; i < N; i++) {
			id[i] = i;  // Initialize with reflexive property, each vertex connected to itself.
		}

		for (int i = 0; i < N; i++) {
			sz[i] = 1;  // Keep track of each tree's size for balance.
		}
	}

	bool connected(int p, int q) { return find(p) == find(q); }

	int find(int);
	void union_edge(int, int);

	int count_connected_components(vector<pair<int,int>>);

private:
	vector<int> id;
	vector<int> sz;
	int count;
};

int WeightedQuickUnionUF::find(int p)
{
	// Follow links recursively to find the tree's root.
	while (p != id[p]) {
		p = id[p];
	}
	return p;
}

void WeightedQuickUnionUF::union_edge(int p, int q)
{
	int i = find(p);
	int j = find(q);
	if (i == j) return;  // Return early if vertices already share a root.

	// Make the smaller tree's root point upstream to the larger tree.
	if (sz[i] < sz[j]) {
		id[i] = j;
		sz[j] += sz[i];
	} else {
		id[j] = i;
		sz[i] += sz[j];
	}
	count--;  // One less connected component.
}

int WeightedQuickUnionUF::count_connected_components(vector<pair<int,int>> graph_connectivity)
{
	for (auto pr : graph_connectivity) {
		auto p = get<0>(pr);
		auto q = get<1>(pr);

		if (connected(p, q)) {
			continue;
		} else {
			union_edge(p, q);
			std::cout << "union_edge( " << p << ", " << q << " )" << std::endl;
		}
	}

	return count;
}

int main (int argc, char* argv[])
{
	using std::cout;
	using std::endl;

	// Read file given on command line.
	std::string filename;
	if (argc != 2) {
		cout << "Usage: union-find ../algs4-data/mediumUF.txt" << endl;
		return EXIT_FAILURE;
	} else {
		filename = argv[1];
	}

	std::ifstream input_file(filename);
	if (!input_file.is_open()) {
		cout << "ERROR: failed to open \"" << filename << "\" for reading." << endl; 
		return EXIT_FAILURE;
	}

	// Read a single integer from the first line indicating the number of pairs N.
	int N = 0;
	input_file >> N;

	// Instantiate a WeightedQuickUnionUF object.
	auto wqu = WeightedQuickUnionUF(N);

	// Read the input data into a vector of pairs representing edges in the graph.
	vector<pair<int,int>> edges;
	edges.reserve(N);
	for (int i = 0; i < N; i++) {
		int p, q;
		input_file >> p >> q;
		edges.push_back(std::make_pair(p, q));
	}
	input_file.close();

	// Apply the weighted quick-union algorithm to the inpur data.
	auto begin = std::chrono::steady_clock::now();
	auto num_cc = wqu.count_connected_components(edges);
	auto end = std::chrono::steady_clock::now();

	// Nice timer code adapted from (https://stackoverflow.com/a/27739925/1615035).
	cout << N << " vertices in graph." << endl
	     << num_cc << " connected components." << endl
		 << "WeightedQuickUnionUF::count_connected_components, elapsed time (ns) = "
	     << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count()
	     << endl;
}