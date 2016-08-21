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

void changeBSTtoDLL(node* root, node** prev, node** head)
{
	if(root==NULL)
		return;
	
	changeBSTtoDLL(root->left, prev, head);
	//cout<<root->data<<" ";
	if(*prev)
	{
		(*prev)->right=root;
		root->left=*prev;
	}
	else *head=root;
	*prev=root;
	changeBSTtoDLL(root->right, prev, head);
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
    	node* temp=NULL, *head=NULL;
	inOrder(root);
	cout<<endl;
	changeBSTtoDLL(root, &temp, &head);
	while(head)
	{
		cout<<head->data<<" ";
		head=head->right;
	}

}

