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

private:
    node* root;
    node* curr;
    void preorder_helper(node*);
    node* insert_helper(int, node*);
    void inorder_helper(node*);
    void postorder_helper(node*);
	
};


#endif
