// Aleksey Leshchuk
// Graph class
// Initialized with a 2 dimensional bool adjacency std::array

#ifndef GRAPH_CPP
#define GRAPH_CPP

#include <iostream>
#include <array>
#include <string>
#include <algorithm>
using namespace std;

template <size_t N>
class Graph {
    public:
	Graph(std::array<array<int,  N>, N> & arr, std::string node_map) : 
	    size(arr.size()),
	    two_d_array(arr),
	    node_mapping(node_map)
	    {
	    }
	bool isomorph (const Graph& graph2) const {
	    if (this->two_d_array.size() != graph2.two_d_array.size() )
		return false;	    // if two graphs have different amount of nodes, quit
	    else {
		int* test_ind = new int[this->two_d_array.size()];
		for (int i=0;i<size;i++)
		    test_ind[i]=i;			    // populate test indices array with values 0 to size-1
		int bijection_count = 0;		    // keeps track of bijections found

		do {
		    bool valid = true;
		    for (int row=0; row<size;row++){
			for (int col=0; col<size; col++){
			    if (this->two_d_array[row][col] != graph2.two_d_array[test_ind[row]][test_ind[col]]){ // if graph1.node != graph2.node
				valid=false;
				break;		// break out of loop
			    }
			}
			if (!valid)
			    break;	// if prev row invalid, break to next permutation
		    }
		    if (valid){
			++bijection_count;	// increment for every valid bijection;
			if (bijection_count==1)
			    cout<<"Bijections: \n";
			for (int i=0;i<size;i++){
			    cout<<i+1<<" -> ";
			    cout<<graph2.node_mapping[test_ind[i]]<<" ";
			    (i!=size-1)?(cout<<"| "):(cout<<endl);
			}
		    }
		} while (next_permutation(test_ind, test_ind+size));
		if (!bijection_count)	    // if no bijections found, not isomorphic
		    cout<<"The Two Graphs Aren't Isomoprhic\n";
		delete[] test_ind;
	    }


	}

	std::string node_mapping;
	int size; 
	array<array<int, N>, N> two_d_array;
};
#endif
