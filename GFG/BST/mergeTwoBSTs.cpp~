#include <stdio.h>
#include <stdlib.h>
 #include <stack>
 #include <iostream>
 
 using namespace std;
 
// Structure of a BST Node
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
 
 
/* Utility function to create a new Binary Tree node */
struct node* newNode (int data)
{
    struct node *temp = new struct node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
 
/* A utility function to print Inoder traversal of a Binary Tree */
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void mergeTwoBSTs(node* root1, node* root2)
{
	if(root1==NULL || root2==NULL)
		return;
		
	stack<node*> S1, S2;
	
	
	while(1)
	{
		while(root1!=NULL)
		{
			S1.push(root1);
			root1=root1->left;
		}
		
		while(root2!=NULL)
		{
			S2.push(root2);
			root2=root2->left;
		}
		
		if(S1.empty() || S2.empty())
			break;
		
		if( S1.top()->data==S2.top()->data )
		{
			root1=S1.top();
			printf("%d ", root1->data);
			root2=S2.top();
			root1=root1->right;
			root2=root2->right;
			S1.pop();
		}
		else if(S1.top()->data<S2.top()->data)
		{
			root1=S1.top();
			printf("%d ", root1->data);
			root1=root1->right;
			S1.pop();
		}
		else
		{
			root2=S2.top();
			printf("%d ", root2->data);
			root2=root2->right;
			S2.pop();
		}
		
	}
	
	while(!S1.empty())
	{
		printf("%d ", S1.top()->data);
		S1.pop();
	}
	
	while(!S2.empty())
	{
		printf("%d ", S2.top()->data);
		S2.pop();
	}
}





/* Driver program to test above functions */
int main()
{
    struct node  *root1 = NULL, *root2 = NULL;
 
    /* Let us create the following tree as first tree
            3
          /  \
         1    5
     */
    root1 = newNode(3);
    root1->left = newNode(1);
    root1->right = newNode(5);
 
    /* Let us create the following tree as second tree
            4
          /  \
         2    6
     */
    root2 = newNode(4);
    root2->left = newNode(2);
    root2->right = newNode(6);
 
    // Print sorted nodes of both trees
    mergeTwoBSTs(root1, root2);
 
    return 0;
}
