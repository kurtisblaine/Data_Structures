#include "ll.h"
using namespace std;

LL::LL()
{
	head = NULL;  
	current = NULL;
	temp = NULL;
}

void LL::prepend(int num)
{
node* newNode = new node;
newNode->val = num;
newNode->next = NULL;

if(head == NULL){
head = newNode;
}

else{
newNode->next = head;
head = newNode;
newNode = NULL;
} 
}

void LL::append(int num)
{
node* newNode= new node;
node* ptr;
newNode->val = num;
newNode->next = NULL;

if (head == NULL){
head = newNode;
}
else{
ptr = head;
while(ptr->next != NULL){
ptr = ptr->next;
}
ptr->next = newNode;
}
}

void LL::print(){
node* tmp = head;
while(tmp != NULL){
cout << tmp -> val << " -> ";
tmp = tmp->next;
}
cout << "NULL" << endl;
}

bool LL::removeFront(){
if(head != NULL){
node* newNode = head;
head = head->next;
newNode -> next = NULL;
delete newNode;
}
}

bool LL::removeBack(){
node* last = head;
node* previousToLast = NULL;
while(last->next != NULL)
{
previousToLast = last;
last = last->next;
}
delete previousToLast->next;
previousToLast->next = NULL;
}


node* LL::search(int num){
node* number = NULL;
temp = head;
current = head;

while(current != NULL && current->val != num){
temp = current;
current = current->next;
}
if(current != NULL){
number = current;
current = current-> next;
return number;
}
}

bool LL::remove(int num){
node* number = NULL;
temp = head;
current = head;

while(current != NULL && current->val != num)
{
temp = current;
current = current->next;
}
if (current == NULL){
delete number;
}
else{
number = current;
current = current->next;
temp->next = current;
if(number == head){
head = head->next;
temp = NULL;
}
delete number;
}
}

