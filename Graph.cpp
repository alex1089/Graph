// Aleksey Leshchuk
// Graph class
// Initialized with a 2 dimensional bool adjacency std::array

#ifndef GRAPH_CPP
#define GRAPH_CPP

using namespace std;
#include <iostream>
#include <array>
#include "Permutation.cpp"

template <int N>
class Graph {
    public:
	Graph(std::array<array<int, N>, N> && arr) : 
	    size(arr.length()),
	    two_d_array(std::move(arr))
	    {
		cout<<"Graph initialize";
	    }
	void operator== (const Graph& graph2) const {
	    // TODO: find if two graphs are isomorphic
	}

    private:
	Permutation perm_gen;
	int size; 
	array<array<int, N>, N> two_d_array;
};
#endif
