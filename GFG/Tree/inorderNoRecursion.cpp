#include <iostream>
#include <stdio.h>
#include <malloc.h>
#include <stack>

using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};

node* newNode(int data)
{
	struct node *Nnode=(node*)malloc(sizeof(node));
	Nnode->data=data;
	Nnode->left=NULL;
	Nnode->right=NULL;
	return Nnode;
}

void inOrder(struct node* root)
{
	node* curr;
	curr=root;
	stack<node*> S;
	
	while(1)
	{
		if(curr)
		{
			S.push(curr);
			curr=curr->left;
		}
		else
		{
			if(S.empty())
				break;
			curr=S.top();
			S.pop();
			cout<<curr->data<<" ";
			curr=curr->right;	
		}
	}
}

int main()
{
	struct node *root = newNode(1);
	root->left        = newNode(2);
	root->right       = newNode(3);
	root->left->left  = newNode(4);
	root->left->right = newNode(5);
	inOrder(root);
}
