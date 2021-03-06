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

void Mirror(node* root)
{
	if(root==NULL)
		return;
	
	node* temp=root->left;
	root->left=root->right;
	root->right=temp;
	Mirror(root->left);
	Mirror(root->right);
}

bool isSameStructure(node* root1, node* root2)
{
	if(root1==NULL && root2==NULL)
		return true;
	
	if(root1==NULL || root2==NULL)
		return false;
	
	return isSameStructure(root1->left, root2->right) && isSameStructure(root1->right, root2->left);
}

bool isFoldable(node* root)
{
	if(root==NULL)
		return true;
	
	//Mirror(root->left);
	return isSameStructure(root->left, root->right);
}

int main()
{
	struct node *root = newNode(1);
    	root->left        = newNode(2);
   	root->right       = newNode(3);
    	root->left->left  = newNode(7);
   	root->left->right = newNode(6);
    	root->right->left  = newNode(5);
    	
	cout<<isFoldable(root)<<endl;
}
