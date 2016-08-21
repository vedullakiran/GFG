#include <stdio.h>
#include<stdlib.h>
#include <iostream>
#include <algorithm>
#define INFI 10000

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

int ceil(node* root, int i)
{
	if(root==NULL)
		return INFI;

	if(root->data==i)
		return i;
	
	if(root->data<i)
		return ceil(root->right, i);
	
	int C=ceil(root->left, i);
	return C<root->data?C:root->data;
}

int main()
{
    node *root = newNode(8);
 
    root->left = newNode(4);
    root->right = newNode(12);
 
    root->left->left = newNode(2);
    root->left->right = newNode(6);
 
    root->right->left = newNode(10);
    root->right->right = newNode(14);
 
    for(int i = 0; i < 16; i++)
        printf("%d  %d\n", i, ceil(root, i));
 
    return 0;
}
