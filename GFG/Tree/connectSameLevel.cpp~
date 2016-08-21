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

void connectSameLevel(node* root)
{
	queue<pair<node*, int> > q;
	q.push(mp(root, 0));
	
	while(1)
	{
		node* curr=q.front().F;
		int l=q.front().S;
		q.pop();
		if(curr->left)
			q.push(mp(curr->left, l+1));
		if(curr->right)
			q.push(mp(curr->right, l+1));
		
		if(q.empty())
			break;
		if(l==q.front().S)
			curr->next=q.front().F;
	}
	
}

int main()
{
	struct node *root = newNode(10);
  	root->left        = newNode(8);
  	root->right       = newNode(2);
  	root->left->left  = newNode(3);
 
  	// Populates next pointer in all nodes
  	connectSameLevel(root);
  	
  	printf("Following are populated next pointers in the tree (-1 is printed if there is no next) \n");
  	printf("next of %d is %d \n", root->data,root->next? root->next->data: -1);
  	printf("next of %d is %d \n", root->left->data,root->left->next? root->left->next->data: -1);
  	printf("next of %d is %d \n", root->right->data,root->right->next? root->right->next->data: -1);
  	printf("next of %d is %d \n", root->left->left->data,root->left->left->next? root->left->left->next->data: -1);
 	
}
