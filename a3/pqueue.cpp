#include "pqueue.h"

using namespace std;

PQUEUE::PQUEUE()
{

	front = NULL;
	back = NULL;

}

void PQUEUE::enq(int num)
{
	node* newNode = new node; 
	newNode->val = num;
	newNode->next = NULL;

	//pointer to walk list
	node* temp;

	if(front == NULL || front->val >= newNode->val){//empty or greater than new value
		newNode->next = front;
		front = newNode;
	}

	else{//less than new value
		temp = front;
		while(temp->next != NULL && temp->next->val < newNode -> val){//find a node's value greater than newNode's value
		temp = temp->next;
	}
	
	//insert node before greater node
	newNode->next = temp->next;
	temp->next = newNode;

	}

}

bool PQUEUE::deq()
{
   
   	 if(!isEmpty())
   	{
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

bool PQUEUE::isEmpty(){

	if(front == NULL && back == NULL){
		return true;
	}

	else{
		return false;
	}
}

node* PQUEUE::getFront(){

	if(!isEmpty()){
		node* frt = front;
		return frt;
	}
	
}

void PQUEUE::printq(){

	node* ptr = front;
	cout << "FRONT: ";
	while(ptr != NULL){
		cout << ptr->val << " -> ";
		ptr = ptr->next;
	}
	cout << "BACK" << endl;
}
