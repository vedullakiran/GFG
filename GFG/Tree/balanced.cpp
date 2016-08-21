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

pair<bool, int> balanced(node* root)
{
	if(root==NULL)
		return mp(true, 0);
	if(root->left==NULL && root->right==NULL)
		return mp(true, 1);
	
	pair<bool, int> p1, p2;
	
	p1=balanced(root->left);
	p2=balanced(root->right);
	
	if(p1.F==false || p2.F==false || (max(p1.S, p2.S)-min(p1.S, p2.S)>1))
		return mp(false, 0);
	else
		return mp(true, max(p1.S, p2.S)+1); 
} 

int main()
{
	  struct node *root = newNode(1);
	  root->left        = newNode(2);
	  root->left->left  = newNode(4);
	  root->left->right = newNode(5);
	  cout<<balanced(root).F<<endl;
}
