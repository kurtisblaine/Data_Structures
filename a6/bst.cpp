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
	cout << endl;	
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

node* BST::findMin(){

node* temp = new node;
temp = root;

	if(temp == NULL){
		return temp;
	}

	while(temp->left != NULL){
		temp = temp->left;
	}

	return temp;

}


node* BST::findMax(){

node* temp = new node;
temp = root;

	if(temp == NULL){
		return temp;
	}

	while(temp->right != NULL){
		temp = temp->right;
	}

	return temp;

}


int BST::findHeight(){
	findHeight_helper(root);
}

int BST::findHeight_helper(node* root){
	if(root == NULL){
		 return 0;
	}

	int leftHeight = findHeight_helper(root->left);
	int rightHeight = findHeight_helper(root->right);

	return 1 + max(leftHeight, rightHeight);
}

int BST::max(int l, int r){
	return ((l>r) ? l:r);
}

bool BST::remove(int val){
	
		remove_helper(val, root);
}

node* BST::remove_helper(int val, node* root){
//find node
	if(root == NULL){
		return NULL;
	}
	
	else if(val < root->val){
		root->left = remove_helper(val, root->left);
	}
	
	else if(val > root->val){
		root->right = remove_helper(val, root->right);
	}
//end find node

	else{
		if(root->left == NULL){
			return root->right;
		}
	
		else if(root->right == NULL){
			return root->left;
		}
		
		node* temp = new node;
		temp = root;

		root = findMinNode(temp->right);
		root->right = deleteMin(temp->right);
		root->left = temp->left;
	}
	return root;
}

node* BST::deleteMin(node* temp){

	if(temp->left == NULL){
		return temp->right;
	}

	node* root = new node;
	root = temp;
	node* parent = new node;

	while(temp != NULL && temp->left != NULL){
		parent = temp;
		temp = temp->left;
	}
	
	parent->left = temp->right;
	return root;
}

node* BST::findMinNode(node* root){

	while(root != NULL && root->left != NULL){
		root = root->left;
	}

	return root;
}
