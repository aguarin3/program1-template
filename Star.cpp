#include "Star.h"
#include "Planet.h"
#include "List.h"
#include "Vector.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Starlist::Starlist(){
	this->planet = new List();
	this->id = 0;
}

Starlist::~Starlist(){
	delete planet;
}

long Starlist::addPlanet(){
	Planet * new_planet = new Planet(rand() % 3001);
	planet->insert(getCurrentNumPlanets(), new_planet);
	return new_planet->getID();
}

bool Starlist::removePlanet(int id){
	for(int i = 0; i < getCurrentNumPlanets(); i++) {
		if(planet->read(i)->getID() == id) {
			planet->remove(i);
			return true;
		}
	}
	return false;
}

Planet* Starlist::getPlanet(int id){
	for(int i = 0; i < getCurrentNumPlanets(); i++) {
		if(planet->read(i)->getID() == id) {
			planet->read(i);
			return planet->read(i);
		}
	}
	return NULL;
}

void Starlist::orbit(){
	for(int i = 0; i < getCurrentNumPlanets(); i++) {
		planet->read(i)->orbit();
	}
}

void Starlist::printStarInfo(){
	std::cout << "The star has " << getCurrentNumPlanets() << " planets." << std::endl;
	std::cout << "Planets:" << std::endl;
	for(int i = 0; i < getCurrentNumPlanets(); i++) {
		std::cout << "\tPlanet " << planet->read(i)->getType() << planet->read(i)->getID()  << " is " << planet->read(i)->getDistance() << " million miles away at position " << planet->read(i)->getPos() << " around the star." << std::endl;
	}
}

unsigned int Starlist::getCurrentNumPlanets(){
	return planet->size();
}
Starvector::Starvector(){
	this->planet = new Vector();
	this->id = 0;
	this->current_planets = 0;
}

Starvector::~Starvector(){
	delete planet;
}

long Starvector::addPlanet(){
	Planet * new_planet = new Planet(rand() % 3001);
	planet->insert(current_planets, new_planet);
	return new_planet->getID(); 
}

bool Starvector::removePlanet(int id){
	for(int i = 0; i < getCurrentNumPlanets(); i++) {
		if(planet->read(i)->getID() == id) {
			planet->remove(i);
			return true;
		}
	}
	return false;
}

Planet* Starvector::getPlanet(int id){
	for(int i = 0; i < getCurrentNumPlanets(); i++) {
		if(planet->read(i)->getID() == id) {
			planet->read(i);
			return planet->read(i);
		}
	}
	return NULL;
}

void Starvector::orbit(){
	for(int i = 0; i < getCurrentNumPlanets(); i++) {
		planet->read(i)->orbit();
	}
}

void Starvector::printStarInfo(){
	std::cout << "The star has " << planet->size() << " planets." << std::endl;
	std::cout << "Planets:" << std::endl;
	for(int i = 0; i < getCurrentNumPlanets(); ++i){
		std::cout << "\tPlanet " << planet->read(i)->getType() << planet->read(i)->getID()  << " is " << planet->read(i)->getDistance() << " million miles away at position " << planet->read(i)->getPos() << " around the star." << std::endl;
	}
}

unsigned int Starvector::getCurrentNumPlanets(){
	return planet->size();
}
