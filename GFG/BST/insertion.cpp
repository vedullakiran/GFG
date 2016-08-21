#include <iostream>
#include <stdio.h>
#include <malloc.h>
using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};

node* newNode(int data)
{
	//cout<<"yes"<<endl;
	node* temp=(node*)malloc(sizeof(node));
	temp->left=NULL;
	temp->right=NULL;
	temp->data=data;
	return temp;
}

node* insert(node* root, int data)
{
	if(root==NULL)
		return newNode(data);
	if(root->data>data)
		root->left=insert(root->left, data);
	if(root->data<data)
		root->right=insert(root->right, data);
	return root;
}

node* search(node* root, int data)
{
	if(root==NULL || root->data==data)
		return root;
	if(root->data>data)
		return search(root->left, data);
	if(root->data<data)
		return search(root->right, data);
}

void inOrder(node* root)
{
	if(root==NULL)
		return;
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

int main()
{
	node* root=NULL;
	root = insert(root, 50);
    	insert(root, 30);
    	insert(root, 20);
    	insert(root, 40);
    	insert(root, 70);
    	insert(root, 60);
    	insert(root, 80);
	inOrder(root);
	cout<<endl;
	if(search(root, 1))
		cout<<"Yes"<<endl;
	else cout<<"No"<<endl;

}

