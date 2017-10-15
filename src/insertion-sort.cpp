//
//  insertion-sort.cpp
//  Copyright © 2017 Dylan Brown. All rights reserved.
//

// NOTES
// Insertion sort works sequentially from the beginning of the array until it encounters
// an element which is not properly sorted compared to the previous element (F is not < D) .
//     [ A B C E F | (D) Q R S ]
// Swap up through the previous entries until we find the appropriate insertion index.
//     [ A B C E (D) F Q R S ]
//     [ A B C D E F | Q R S ]
// Continue from the index | shown above. Note that we conduct ~(n^2 / 4 compares and swaps) on
// average (worst case n^2 / 2) to create an ascending sort of comparable items in time O(n^2).

#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <string>
#include <utility>
#include <cstdlib>

using std::cout;
using std::endl;
using std::vector;
using std::string;

template<typename T> class Insertion {
public:
    // Requirement: T must implement comparison operators.
    void sort(vector<T>& a);

    bool is_sorted(const vector<T>& a) {
        for (int i = 1; i < a.size(); i++) {
            if ( less(a[i], a[i-1]) ) { return false; }
        }
        return true;
    }

    void show(const vector<T>& a) {
        for (auto item : a) {
            cout << item << " ";
        }
        cout << endl;
    }

private:
    // Returns true if v < w. Again, T must implement comparison operators.
    bool less(T v, T w) { return (v < w); }
    // Pass by reference to ensure std::swap mutates the caller's data.
    void exch(vector<T>& a, int i, int j) { std::swap(a[i], a[j]); }
};

template<typename T> void Insertion<T>::sort(vector<T>& a)
{
    int N = a.size();
    for (int i = 1; i < N; i++) {
        // show(a); // Debug
        for (int j = i; j > 0 && less(a[j], a[j-1]); j--) {
            exch(a, j, j-1);   
        }
    }
}

int main (int argc, char* argv[])
{
    // Read file given on command line.
    string filename;
    if (argc != 2) {
        cout << "Usage: insertion-sort ../algs4-data/words3.txt" << endl;
        return EXIT_FAILURE;
    } else {
        filename = argv[1];
    }

    std::ifstream input_file(filename);
    if (!input_file.is_open()) {
        cout << "ERROR: failed to open \"" << filename << "\" for reading." << endl; 
        return EXIT_FAILURE;
    }

    // Instantiate a insertion sort object.
    auto ins = Insertion<string>();

    // For this example, we'll sort strings in alphabetical order.
    // Read the input data into a vector of std::string tokens.
    vector<string> tokens;
    string tkn;
    while ( input_file >> tkn ) {
        tokens.push_back(tkn);
    }
    input_file.close();

    // Apply the weighted quick-union algorithm to the input data.
    auto begin = std::chrono::steady_clock::now();
    ins.sort(tokens);
    auto end = std::chrono::steady_clock::now();

    // Ensure that the data structure is sorted.
    if (!ins.is_sorted(tokens)) {
        cout << "ERROR: upon review, insertion sort failed to completely sort the data." << endl; 
        return EXIT_FAILURE;
    }

    // Output the performance and results.
    cout << "Insertion::sort, elapsed time (ns) = "
         << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count()
         << endl;
    ins.show(tokens);
}
