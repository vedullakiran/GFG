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

pair<int, int> diameter(node* root)
{
	if(root==NULL)
		return mp(0,0);
	if(root->left==NULL && root->right==NULL)
		return mp(1,1);
	
	pair<int, int> p1, p2;
	p1=diameter(root->left);
	p2=diameter(root->right);
	
	int f=0, s=0;
	
	if(p1.F+p2.F+1>max(p1.S, p2.S))
		s=p1.F+p2.F+1;
	else
		s=max(p1.S, p2.S);
	
	f=1+max(p1.F, p2.F);
	
	return mp(f, s);
}

int main()
{
	  struct node *root = newNode(1);
	  root->left        = newNode(2);
	  root->right       = newNode(3);
	  root->left->left  = newNode(4);
	  root->left->right = newNode(5);
	  cout<<diameter(root).second<<endl;
}
