#ifndef STARH_AG
#define STARH_AG
#include "Planet.h"
#include "List.h"
#include "Vector.h"
#include <iostream>

class Starlist{
	private:
		List* planet;
		int id;
		int current_planets;
	public:
		Starlist();
		~Starlist();
		long addPlanet();
		bool removePlanet(int);
		Planet* getPlanet(int);
		void orbit();
		void printStarInfo();
		unsigned int getCurrentNumPlanets();
		//Node* getHead(){return this->head;};
		//Planet* getP(){return this->p;};
};

class Starvector{
	private:
		Vector* planet;
		int id;
		int current_planets;
	public:
		Planet** planets;
		Starvector();
		~Starvector();
		long addPlanet();
		bool removePlanet(int);
		Planet* getPlanet(int);
		void orbit();
		void printStarInfo();
		unsigned int getCurrentNumPlanets();
};

#endif
