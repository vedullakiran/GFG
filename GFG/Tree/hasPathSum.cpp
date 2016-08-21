#include <iostream>
#include <stdio.h>
#include <malloc.h>
#include <stack>
#define mp make_pair 
#define F  first
#define S  second

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

bool hasPathSum(int sum, node* root)
{
	if(sum==0 && root==NULL)
		return true;
	if(root==NULL)
		return 0;

	return hasPathSum(sum-root->data, root->left) || hasPathSum(sum-root->data, root->right);
}

int main()
{
	struct node *root = newNode(10);
  	root->left        = newNode(8);
  	root->right       = newNode(2);
  	root->left->left  = newNode(3);
  	root->left->right = newNode(5);
  	root->right->left = newNode(2);
	cout<<hasPathSum(23, root)<<endl;
}
