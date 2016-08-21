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

pair<bool, int> isSumTree(node* root)
{
	if(root==NULL)
		return mp(true, 0);
	
	if(root->left==NULL && root->right==NULL)
		return mp(true, root->data);
		
	pair<bool ,int> p1, p2;
	
	p1=isSumTree(root->left);
	p2=isSumTree(root->right);
	
	if(p1.F && p2.F && (p1.S+p2.S==root->data))
		return mp(true, 2*root->data);
	
	return mp(false, 0);
}

int main()
{
	struct node *root  = newNode(26);
    	root->left         = newNode(10);
    	root->right        = newNode(3);
    	root->left->left   = newNode(4);
    	root->left->right  = newNode(6);
    	root->right->right = newNode(3);
 	cout<<isSumTree(root).F<<endl;
}
