// Permutation class 
// Aleksey Leshchuk
// CISP440

#include <iostream>
#include "Counting.cpp"

class Permutation: private Counting {
	int working_ind;		// working index for generating permutations
	int last_position;	// tracker of index last incremented
	int one_nine[9] ;	// permuations array
    public:
	Permutation (int total, int choose):
	    Counting(total, choose)
	{
	    sets = factorial(total)/factorial(total-choose);
	    working_ind=choose_num-1;	// initialize working index for generating permutations
	    last_position=choose_num-2;	// tracher of last element incremented, starts at n-1
	    // initialize one_nine permutation array
	    for (int i=0;i<9;i++)
		one_nine[i]=i+1;
	}
	void print() {

	    bool fail=false;
	    static int break_counter=0;
	    // print first permutation
	    //for (int i=0;i<choose_num;i++)
	//	std::cout<<one_nine[i];
	 //   std::cout<<" ";
	    for (int i=0;i<sets-1;i++){	// TODO: fix limit o sets
		do {
		    int doubles[9]={0};	// stats tracker for multiple occurences of a digit
		    one_nine[working_ind]++;
		    fail=false;
		    do {
			if (one_nine[working_ind]>total_num){ // overflow
			    one_nine[working_ind]=1;    // set
			    one_nine[working_ind-1]++;
			}
			if (last_position>working_ind-1 && working_ind>0){
			    last_position=working_ind-1;
			}
		    } while (one_nine[working_ind]>total_num);
		    working_ind=choose_num-1;
		    
		    for (int exist=0; exist<choose_num;exist++){	    //test for elementN == elementX
			doubles[one_nine[exist]]++;
			if (doubles[one_nine[exist]]>1)			// if same number appears >1, fail
			    fail=true;
		    }
		    
	    
		} while (fail);
		working_ind=choose_num-1;	// reset working index to last position

		for (int ii=0;ii<choose_num;ii++)
		       std::cout<<one_nine[ii];
		std::cout<<" ";
	        break_counter++;
		if (!(break_counter%7))
		    std::cout<<std::endl;
	    }
	    std::cout<<std::endl;
	    std::cout<<"There are "<<sets<<" permutations.\n";
	}
};
