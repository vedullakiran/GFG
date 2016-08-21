#include <iostream>
#include <stdio.h>
#include <malloc.h>
#include <stack>
#include <queue>
#define mp make_pair 
#define F  first
#define S  second

using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
	struct node* next;
};

node* newNode(int data)
{
	struct node *Nnode=(node*)malloc(sizeof(node));
	Nnode->data=data;
	Nnode->left=NULL;
	Nnode->right=NULL;
	Nnode->next=NULL;
	return Nnode;
}

node* constructTree(int A[], int start, int end)
{
	if(start>end)
		return NULL;
	if(start==end)
		return newNode(A[start]);
	int m=start;
	for(int i=start+1, i<=end; i++)
		if(A[m]<A[i])
			m=i;
	
	node* curr=newNode(A[m]);
	curr->left=constructTree(A, start, m-1);
	curr->right=cinstructTree(A, m+1, end);
	
	return curr;
}

void printInorder (struct node* node)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printInorder (node->left);
 
    /* then print the data of node */
    printf("%d ", node->data);
 
    /* now recur on right child */
    printInorder (node->right);
}

int main()
{
	int inorder[] = {5, 10, 40, 30, 28};
    	int len = sizeof(inorder)/sizeof(inorder[0]);
    	struct node *root =constructTree(inorder, 0, len - 1);
 
   	 /* Let us test the built tree by printing Insorder traversal */
   	printf("\n Inorder traversal of the constructed tree is \n");
    	printInorder(root);
    	return 0;
}
