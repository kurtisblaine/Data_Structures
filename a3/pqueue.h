#ifndef PQ_H
#define PQ_H

// include this library to use NULL, otherwise use nullptr instead
#include <cstddef>
#include <iostream>

/* Struct which will be the building block of our list */
struct node{
	int val;
	node* next;
};

/* Linked list class definition */
class PQUEUE{
public:
	PQUEUE();
	void enq(int);
	bool deq();
    	bool isEmpty();
    	node* getFront();
	void printq();
private:
	node* front;
    	node* back;
};

#endif
