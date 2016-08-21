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

node* constructTree(int *idx, int pre[], char preLN[])
{
	node* curr=newNode(pre[*idx]);
	if(preLN[*idx]=='L')
		return curr;
	++(*idx);
	curr->left=constructTree(idx, pre, preLN);
	++(*idx);
	curr->right=constructTree(idx, pre, preLN);
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
    struct node *root = NULL;
 
    /* Constructing tree given in the above figure
          10
         /  \
        30   15
       /  \
      20   5 */
    int pre[] = {10, 30, 20, 5, 15};
    char preLN[] = {'N', 'N', 'L', 'L', 'L'};
    int n = sizeof(pre)/sizeof(pre[0]);
 
    // construct the above tree
    int i=0;
    root = constructTree (&i, pre, preLN);
 
    // Test the constructed tree
    printf("Following is Inorder Traversal of the Constructed Binary Tree: \n");
    printInorder (root);
 
    return 0;
}

