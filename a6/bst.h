#ifndef BST_H
#define BST_H

// include this library to use NULL, otherwise use nullptr instead
#include <cstddef>
#include <iostream>


/* Struct which will be the building block of our list */
struct node{
	int val;
	node* left;
    	node* right;
};

class BST{
public:
    BST();
    void insert(int);
    void inorder();
    void postorder();
    void preorder();
    node* search(int);
    bool remove(int);
    node* findMax();
    node* findMin();
    int findHeight();

private:
    node* root;
    node* curr;
    node* parent;
    node* newNode;
    void preorder_helper(node*);
    node* insert_helper(int, node*);
    void inorder_helper(node*);
    void postorder_helper(node*);
    node* remove_helper(int, node*);
    node* deleteMin(node*);
    node* findMinNode(node*);
    int max(int, int);
    int findHeight_helper(node*);
};


#endif
