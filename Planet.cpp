#include "Planet.h"
#include <iostream>

using namespace std;

Planet::Planet(int distance){
	this->distance = distance;
	this->id = (long int) this;
	//char type need
	char p[] = {'h', 'r', 'g'};
	this->type = p[rand()%3];

    	this->pos = rand() % 360;
}

int Planet::orbit(){
	if(this->pos > 358 || this->pos < 0){
		this->pos = 0;
	}
	else{
		this->pos += 1;
	}
	return this->pos;
}
