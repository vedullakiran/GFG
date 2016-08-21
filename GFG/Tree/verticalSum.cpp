#include <iostream>
#include <stdio.h>
#include <malloc.h>
#include <stack>
#include <queue>
#include <map>
#define mp make_pair 
#define F  first
#define S  second

using namespace std;
map<int, int> hash;
map<int, int>::iterator it;

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

void verticalSum(node* root, int key)
{
	if(root==NULL)
		return;
	
	if(hash[key]==0)
		hash[key]=root->data;
	else
		hash[key]+=root->data;
		
	verticalSum(root->left, key-1);
	verticalSum(root->right, key+1);
}

int main()
{
	node* root = newNode(3);
    	root->left = newNode(2);
    	root->right = newNode(5);
    	root->left->left = newNode(1);
   	root->left->right = newNode(4);
  	verticalSum(root, 0);
  	for(it=hash.begin(); it!=hash.end(); ++it)
  		cout<<it->S<<endl;
 	
}
