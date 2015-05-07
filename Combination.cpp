// Combination Class
// Aleksey Leshchuk
// CISP440

#include <iostream>
#include "Counting.cpp"

using namespace std;

class Combination: public Counting {
    public:
    // constructor
    Combination(int size, int choose):
	Counting(size, choose)
    {
	sets=factorial(size)/factorial(size-choose)/factorial(choose);
    }

    void print()  {
	int one_nine[9]={1,2,3,4,5,6,7,8,9};
	int length=choose_num;
	int size=total_num;
	int index=length-1;
	int last_changed=index;
	bool fail=false;

	for (int gen=0;gen<sets;gen++){
	    for (int i=0;i<length;i++)
		cout<<one_nine[i];
	    if (!((gen+1)%4))
		cout<<endl;
	    else
		cout<<" ";
	    one_nine[index]++;
	    do {
		fail=false;
		if (one_nine[index]>size-length+index+1 && index>0){ // TODO: fix for 9
		    index--;
		    one_nine[index]++;
		    one_nine[index+1]=one_nine[index]+1;
		    fail=true;
		}
		if (last_changed>=index){
		    if (last_changed>index)
			last_changed--;
		    for (int adjust=last_changed+1; adjust<length; adjust++){
			one_nine[adjust]=one_nine[adjust-1]+1;
		    }
		}
	    } while (fail);
	    index=length-1;
	}
	cout<<endl;
	cout<<"There are "<<sets<<"\n"<<total_num<<" Choose "<<choose_num<<"\nCombinations\n";
    }
};
		    
		
