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

void convertTree(node* root)
{
	if(root==NULL || (root->left==NULL && root->right==NULL))
		return;
	
	convertTree(root->left);
	convertTree(root->right);
	
	int l=0, r=0;
	
	if(root->left!=NULL)
		l=root->left->data;
	if(root->right!=NULL)
		r=root->right->data;
	
	if(root->data<l+r)
		root->data=l+r;
	else if(root->data>l+r)
	{
		if(root->left!=NULL)
		{
			while(root->left!=NULL)
			{
				root->left->data+=root->data-l-r;
				root=root->left;
			}
		}
		else
		{
			while(root->right!=NULL)
			{
				root->right->data+=root->data-l-r;
				root=root->right;
			}
		}
	}
	
}

void inorder(node* root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
	
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
    	inorder(root);
	cout<<endl;
	convertTree(root);
	cout<<endl;
	inorder(root);
}
