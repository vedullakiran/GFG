#include <stdio.h>
#include<stdlib.h>
#include <algorithm>
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
 
int LCA(node* root, int n1, int n2)
{
	if(root==NULL)
		return -1;
	
	if(root->data==n1 || root->data==n2)
		return root->data;
	
	int l, r;
	l=LCA(root->left, n1, n2);
	r=LCA(root->right, n1, n2);
	if(l==n1 && r==n2)
		return root->data;
	if(l==-1 && r==-1)
		return -1;
	
	if(l!=-1)
		return l;
	return r;
}
 
int main()
{
    struct node *root        = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);
 
    int n1 = 10, n2 = 14;
    int t= LCA(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t);
 
    n1 = 14, n2 = 8;
    t = LCA(root, max(n1, n2), min(n1, n2));
    printf("LCA of %d and %d is %d \n", n1, n2, t);
 
    n1 = 10, n2 = 22;
    t = LCA(root, min(n1, n2), max(n1, n2));
    printf("LCA of %d and %d is %d \n", n1, n2, t);
 
    getchar();
    return 0;
}
