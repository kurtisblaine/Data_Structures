#include "bst.h"

using namespace std;

BST::BST()
{
    root = NULL;
}

void BST::inorder(){

	cout << "In order traversal: ";
	inorder_helper(root);
	cout << endl;

}

void BST::inorder_helper(node* root){

	if(root == NULL){	
		return;
	}

	else{
		inorder_helper(root->left);
		cout << root->val << " ";
		inorder_helper(root->right);
	}
	
}

void BST::postorder(){

	cout << "Post order traversal: ";
	postorder_helper(root);
	cout << endl;
}

void BST::postorder_helper(node* root){

	if(root == NULL){
		return;
	}	
	else{
		postorder_helper(root->left);
		postorder_helper(root->right);
		cout << root->val << " ";
	}

}

void BST::preorder(){

	cout << "Pre order traversal: ";
	preorder_helper(root);	
}

void BST::preorder_helper(node* root){

	if(root == NULL){
		return;
	}
	
	else{
		cout << root->val << " ";
		preorder_helper(root->left);
		preorder_helper(root->right);
	}

}

void BST::insert(int val)
{
    root = insert_helper(val, root);
}

node* BST::insert_helper(int val, node* leaf)
{	
	if(leaf == NULL)	{
		node* leaf = new node;
		leaf->val = val;
		leaf->left = NULL;
		leaf->right = NULL;
		return leaf;
	}

	else if(val < leaf->val){
		leaf->left = insert_helper(val, leaf->left);
	}

	else{
		leaf->right = insert_helper(val, leaf->right);
	}
	return leaf;

}

node* BST::search(int val)
{	

	node* newNode = new node;
	newNode = root;

	while(newNode != NULL){

		if(newNode->val == val){
			return newNode;
		}

		else {
	
			if(val > newNode->val){
				newNode = newNode->right;
			}
	
			else{
				newNode = newNode->left;
			}
				
		}
	}
	return newNode;
}

