#ifndef PLANETH_AG
#define PLANETH_AG
#include <iostream>

class Planet{
	private:
		long int id;
		int pos;
		int distance;
		char type;
	public:
		Planet(int);
		int orbit();
	        long int getID(){return (long int) this;};
        	int getDistance(){return this->distance;};
        	int getPos(){return this->pos;};
		char getType(){return type;}
		//you may add any additional methods you may need.
};

#endif
