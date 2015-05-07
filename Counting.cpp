// Counting Class
// Aleksey Leshchuk
// CISP440

#ifndef COUNTING_CPP
#define COUNTING_CPP
class Counting {
    public:
	// constructor
	Counting(int total, int choose):
	    total_num(total),
	    choose_num(choose) {}

	// virtual print method
	virtual void print()  = 0;

	// recursive factorial 
	int factorial (int x) {
	    if (x == 1 || x == 0) // 1!
		return 1;
	    return x*factorial(x-1);
	}

	int total_num;
	int choose_num;
	int sets;
};

#endif
