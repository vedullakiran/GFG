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

node* kSmallest(node* root, int *k)
{
	if(root==NULL)
		return NULL;
	node* temp=kSmallest(root->left, k);
	
	if(temp)
		return temp;
	if(--*k==0)
		return root;
	
	return kSmallest(root->right, k);
}
 
int main()
{
 	struct node* root = NULL;
  	root = insert(root, 20);
  	insert(root, 8);
  	insert(root, 4);
  	insert(root, 12);
  	insert(root, 10);
  	insert(root, 14);  
 	insert(root, 22);
 	int k=5;
  	cout << kSmallest(root, &k)->data << " ";
  	
  	return 0;    
}
