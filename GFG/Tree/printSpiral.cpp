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

void printSpiral(struct node* root)
{
	stack<node*> s1, s2;
	if(root!=NULL)
		s1.push(root);
	else
		return;
		
	while(!s1.empty() || !s2.empty())
	{
		while(!s1.empty())
		{
			if(s1.top()->right!=NULL)
				s2.push(s1.top()->right);
			if(s1.top()->left!=NULL)
				s2.push(s1.top()->left);
			cout<<s1.top()->data<<" ";
			s1.pop();
		}
		
		cout<<endl;
		while(!s2.empty())
		{
			if(s2.top()->left!=NULL)
				s1.push(s2.top()->left);
			if(s2.top()->right!=NULL)
				s1.push(s2.top()->right);
			
			cout<<s2.top()->data<<" ";
			s2.pop();
		}
		cout<<endl;
	}
}

int main()
{
	struct node *root = newNode(1);
    	root->left        = newNode(2);
   	root->right       = newNode(3);
    	root->left->left  = newNode(7);
   	root->left->right = newNode(6);
    	root->right->left  = newNode(5);
    	root->right->right = newNode(4);
	printSpiral(root);
}
