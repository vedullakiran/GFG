#include <stdio.h>
#include<stdlib.h>
 
struct node 
{
    int data;
    struct node* left;
    struct node* right;
};
 
struct node* newNode(int data) 
{
  	struct node* node = (struct node*)malloc(sizeof(struct node));
  	node->data  = data;
  	node->left  = NULL;
  	node->right = NULL;
   	return(node);
}
 
struct node* insert(struct node* node, int data) 
{
 	if (node == NULL) 
    		return(newNode(data));  
  	else
  	{
    		if (data <= node->data) 
        		node->left  = insert(node->left, data);
    		else
        		node->right = insert(node->right, data);
   
	    	return node; 
  	}
}
 
int minValue(node* root)
{
	if(root==NULL)
		return -1;
	if(root->left!=NULL)
		return minValue(root->left);
	return root->data;
} 
 
int main()
{
 	struct node* root = NULL;
  	root = insert(root, 4);
  	insert(root, 2);
  	insert(root, 1);
  	insert(root, 3);
  	insert(root, 6);
  	insert(root, 5);  
 
  	for (int k=1; k<=7; k++)
       cout << kSmallest(root, k) << " ";
  	getchar();
  	return 0;    
}
