#ifndef VECTORH_AG
#define VECTORH_AG
#include "Planet.h"
#include <iostream>

class Vector{
	private:
		int current_planets;
		Planet ** vector;
	public:
		Vector();
		~Vector();
		void insert(int, Planet*);
		Planet* read(int);
		bool remove(int);
		unsigned size();
};

#endif
