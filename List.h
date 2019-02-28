#ifndef LISTH_AG
#define LISTH_AG
#include "Planet.h"
#include <iostream>
class Node{
        private:
		Planet * data;
        public:
                Node* next;
                Node* prev;
		Node() {this->data = NULL; this->next = NULL; this->prev = NULL;};
		Node(Planet * data) {this->data = data; this->next = NULL; this->prev = NULL;};
		~Node();
                Planet* getData(){return this->data;};
};

class List{
        private:
                unsigned int length;
		Node * head;
		Node * tail;
        public:
                List();
                ~List();
                void insert(int, Planet*);
                Planet* read(int);
                bool remove(int);
                unsigned int size(){return (this->length);};
                Node* getHead(){return this->head;};
};
#endif

