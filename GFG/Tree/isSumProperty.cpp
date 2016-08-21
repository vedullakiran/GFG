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

bool isSumProperty(node* root)
{
	if(root==NULL)
		return true;
	int l=0, r=0;
	
	if(root->left!=NULL)
		l=root->left->data;
	if(root->right!=NULL)
		r=root->right->data;
	
	if(root->data!=l+r && root->right!=NULL && root->left!=NULL)
		return false;
	
	return isSumProperty(root->left) && isSumProperty(root->right);	
}

int main()
{
	  struct node *root  = newNode(10);
	  root->left         = newNode(8);
	  root->right        = newNode(2);
	  root->left->left   = newNode(3);
	  root->left->right  = newNode(5);
	  root->right->right = newNode(2);
	  if(isSumProperty(root))
	    printf("The given tree satisfies the children sum property ");
	  else
	    printf("The given tree does not satisfy the children sum property ");
	 
	  getchar();
	  return 0;
}
