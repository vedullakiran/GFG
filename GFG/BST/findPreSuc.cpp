#include <stdio.h>
#include<stdlib.h>
#include <iostream>

using namespace std;


struct node 
{
    int data;
    struct node* left;
    struct node* right;
};
 
struct node* newNode(int data) 
{
  	struct node* node = (struct node*)malloc(sizeof(struct node));
  	node->data  = data;
  	node->left  = NULL;
  	node->right = NULL;
   	return(node);
}
 
struct node* insert(struct node* node, int data) 
{
 	if (node == NULL) 
    		return(newNode(data));  
  	else
  	{
    		if (data <= node->data) 
        		node->left  = insert(node->left, data);
    		else
        		node->right = insert(node->right, data);
   
	    	return node; 
  	}
}
 
void findPreSucc(int *pre, int *succ, int key, node* root)
{
	if(root==NULL)
		return;
	
	if(root->data> key && root->data<*succ)
	{
		*succ=root->data;
		findPreSucc(pre, succ, key, root->left);
	}
	else if(root->data< key && root->data>*pre)
	{
		*pre=root->data;
		findPreSucc(pre, succ, key, root->right);
	}
	else
	{
		findPreSucc(pre, succ, key, root->left);
		findPreSucc(pre, succ, key, root->right);
	}
}
 
int main()
{
 	int pre=-1000, succ=1000;
 	node* root=NULL;
 	root = insert(root, 50);
    	insert(root, 30);
    	insert(root, 20);
    	insert(root, 40);
    	insert(root, 70);
    	insert(root, 60);
    	insert(root, 80);
 	findPreSucc(&pre, &succ, 20 , root);
 	
 	if (pre != -1000)
      		cout << "Predecessor is " << pre<< endl;
    	else
      		cout << "No Predecessor";
 
    	if (succ != 1000)
      		cout << "Successor is " << succ;
    	else
      		cout << "No Successor";
  	return 0;    
}
