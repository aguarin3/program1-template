#include "Vector.h"
#include "Planet.h"
#include "Star.h"
#include <iostream>

using namespace std;

Vector::Vector(){
	//create internal array on the heap (using new)
	//this->vector = new Planet*[0];
	this->vector = NULL;
	this->current_planets = 0;
}

Vector::~Vector(){
	//A destructor to clean up memory
	//delete all Planets
	for(int i = 0; i < current_planets; i++){
		delete vector[i];
		vector[i] = NULL;
	}
	delete[] vector;
	vector = NULL;
}

void Vector::insert(int index, Planet* p){
        if(index < 0) {
                return;
        }
        else if(index < current_planets){
                Planet** array1 = new Planet* [current_planets+1];
                for(int i = 0; i < index; i++){
                        array1[i] = vector[i];
                }

                array1[index] = p;


                for(int j = index; j < this->current_planets; j++){
                        array1[j+1] = vector[j];
                }
                delete[] vector;
                vector = array1;
                this->current_planets++;
        }
        else{
                Planet** array2 = new Planet* [index + 1];
                for(int i = 0; i < this->current_planets; i++){
         array2[i] = vector[i];
                }
                for(int i = this->current_planets; i < index; i++) {
                        array2[i] = NULL;
                }
                array2[index] = p;
                delete[] vector;
                vector = array2;
                this->current_planets = index + 1;
        }
}

Planet* Vector:: read(int index){
        if(index > this->current_planets || index < 0){
                return NULL;
        }
        else{
                return vector[index];
        }
}

bool Vector::remove(int index){
	if(index >= current_planets|| index < 0){return false;}
        Planet** array = new Planet*[current_planets];
	for (int arr_i = 0, vec_i = 0; vec_i < current_planets; arr_i++, vec_i++) {
		if (vec_i != index) {
			array[arr_i] = vector[vec_i];
		} 
		else {
			arr_i--;
		}
	}
	delete vector[index];
	vector[index] = NULL;
	delete[] vector;
	vector = NULL;
	vector = array;
	current_planets--;
	return true;
}

unsigned Vector::size(){
        return current_planets;
}

/*
void Vector::insert(int index, Planet* p){
	if(index < current_planets){
		Planet** array1 = new Planet* [current_planets+1];
		for(int i = 0; i < index; i++){
			array1[i] = vector[i];
		}
		array1[index] = p;
		for(int j = index+1; j < current_planets+1; j++){
			array1[j] = vector[j-1];
		}
		delete[] vector;
		vector = array1;
		current_planets++;
	}
	else{
		Planet** array2 = new Planet* [index + 1];
		for(int i = 0; i < current_planets; i++){
			array2[i] = vector[i];
		}
		array2[index] = p;
		delete[] vector;
		vector = array2;
		current_planets = index + 1;
	}

}

Planet* Vector:: read(int index){
	if(index > current_planets){
		return NULL;
	}
	else{
		return vector[index];
	}
}

bool Vector::remove(int index){
	Planet** array = new Planet* [current_planets-1];

	for(int i = 0; i < current_planets-index; i++){
		array[i] = vector[i];
	}

	int num = current_planets-index + 1;

	for(int j = current_planets-index; j < current_planets-1; j++){
		array[j] = vector[num];
		num++;
	}

	delete vector[index];
	vector[index] = NULL;
	current_planets--;
	//delete[] vector;
	vector = array;
}

unsigned Vector::size(){
	return current_planets;
}
*/
