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

/*node* constructBST(int A[], int start, int end)
{
	if(start>end)
		return NULL;
	
	int i=start+1;
	while(i<=end && A[i]<A[start])
		i++;
	//cout<<i<<endl;
	node* temp=newNode(A[start]);
	temp->left=constructBST(A, start+1, i-1);
	temp->right=constructBST(A, i, end);
	return temp;
		
}
*/

node* constructBST(int A[], int min, int max, int n, int *idx)
{
	if(*idx==n || min>A[*idx] || max<A[*idx])
		return NULL;
	
	node* temp=newNode(A[*idx]);
	int val=A[*idx];
	++*idx;
	temp->left=constructBST(A, min, val, n, idx);
	temp->right=constructBST(A, val, max, n, idx);
	return temp;	
}

void printInorder(node* root)
{
	if(root==NULL)
		return;
	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
		
}


int main ()
{
    int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof( pre ) / sizeof( pre[0] );

    int idx=0;
    struct node *root = constructBST(pre,-1000, 1000, size, &idx);

    printf("Inorder traversal of the constructed tree: \n");
    printInorder(root);

    return 0;
}
