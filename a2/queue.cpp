#include "queue.h"
using namespace std;

QUEUE::QUEUE()
{
	front = NULL;
    	back = NULL;
	
}

void QUEUE::enq(int num)
{
	node* newNode = new node;
	newNode->val = num;
	newNode->next = NULL;
	
	if(front == NULL){
		front = newNode;
		back = newNode;	
		back->next = NULL;
	}

	else{
		back->next = newNode;
		back = newNode;
		back->next = NULL;
	}
}

bool QUEUE::deq()
{
	if(!isEmpty()){
		node* tmp = front;
		front = front -> next;
		tmp -> next = NULL;
		delete tmp; 
		return true;
	}
	else{
		return false;
	}
   
}

bool QUEUE::isEmpty(){
	if(front==NULL && back==NULL){
		return true;
	}
	else{
		return false;
	}
}

node* QUEUE::getFront(){
	if(!isEmpty()){
		node* gfrt = front;
		return front;
	}

}

void QUEUE::printq(){
	node* ptr = front;
	cout << "FRONT: ";
	while(ptr != NULL){
		cout << ptr->val << " -> ";
		ptr = ptr->next;
	}
	cout << "BACK" << endl;
}
