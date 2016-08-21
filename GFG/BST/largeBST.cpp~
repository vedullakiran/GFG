#include <stdio.h>
#include<stdlib.h>
#include <iostream>
#include <algorithm>
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

int largeBST(node* root, int *mini, int *maxi)
{
	if(root==NULL)
		return 0;
	int l=largeBST(root->left, mini, &(root->data));
	int r=largeBST(root->right, &(root->data), maxi);
	
	if(root->left==NULL && root->right==NULL)
		return 1;
	if(mini<root->data && maxi>root->data)
	{	
		if(root->left==NULL && r!=0)
			return r+1;
		if(root->right==NULL && l!=0)
			return l+1;
		if(l!=0 && r!=0)
			return r+l+1;
		return max(l, r);
	}
	return 0;
}

int main()
{
 	struct node *root = newNode(50);
  	root->left        = newNode(10);
  	root->right       = newNode(60);
  	root->left->left  = newNode(5);
  	root->left->right = newNode(20);
  	root->right->left  = newNode(55);
  	root->right->left->left  = newNode(45);
  	root->right->right = newNode(70);
 	root->right->right->left = newNode(65);
  	root->right->right->right = newNode(80);
 
  	 printf(" Size of the largest BST is %d", largeBST(root, -1000, 1000));
  	 cout<<endl;
  	//getchar();
  	return 0;    
}
