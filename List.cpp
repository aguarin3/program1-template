#include "List.h"
#include "Planet.h"
#include "Star.h"
#include <iostream>

using namespace std;

List::List(){
	this->head = NULL;
	this->tail = NULL;
	this->length = 0;
}

List::~List(){
	if(head == NULL) {
		return;
	}
	while(tail != head) {
		tail = tail->prev;
		delete tail->next;
		tail->next = NULL;
	}
	delete head;
	head = NULL;
	tail = NULL;
}

Node::~Node() {
	delete data;
}

//Got advice from https://www.geeksforgeeks.org/doubly-linked-list/
void List::insert(int index, Planet * p) {
	if(index < 0) {
		return;
	}
	if(head == NULL) {
		this->length++;
		head = new Node(p);
		tail = head;
	}
	else if(index > this->length-1) {
		Node * node = new Node(p);
		tail->next = node;
		node->prev = tail;
		tail = node;
		this->length++;
	}
	else if(index == 0) {
		Node * node = new Node(p);
		head->prev = node;
		node->next = head;
		head = node;
		this->length++;
	}
	else {
		Node * current = head;
		int i = 0;
		while(i < index) {
			i++;
			current = current->next;
		}
		Node * last;
		Node * node = new Node(p);
		last = current->prev;
		last->next = node;
		node->prev = last;
		current->prev = node;
		node->next = current;
	}
}


Planet* List::read(int index){
	if(index < 0|| index >= this->length) {
		return NULL;
	}
	else {
		Node * current = head;
		int i = 0;
		while(i < index) {
			i++;
			current = current->next;
		}
		return current->getData();
	}
}

bool List::remove(int index){
	if(index < 0 || head == NULL || index > this->length-1) {
		return false;
	}
	else if(index == 0) {
		if(this->length == 1) {
			delete head;
			head = NULL;
			this->length--;
		}
		if(this->length > 1) {
			head = head->next;
			delete head->prev;
			head->prev = NULL;
			this->length--;
		}
		return true;
	}
	else if(index == this->length-1) {
		tail = tail->prev;
		delete tail->next;
		tail->next = NULL;
		this->length--;
		return true;
	}
	else {
		Node * current = head;
		Node * front;
		Node * back;
		int i = 0;
		while(i < index) {
			i++;
			current = current->next;
		}
		front = current->prev;
		back = current->next;
		delete current;
		current = NULL;
		front->next = back;
		back->prev = front;
		this->length--;
		return true;
	}
}
