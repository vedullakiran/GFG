#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;
 
Node* newNode( int data )
{
    Node* temp = (Node *)malloc( sizeof( Node ) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
Node* createBST(int a[], int * i, int min, int max, int n)
{
	if(*i==n)
		return NULL;

	if(a[*i]>min && a[*i]<max)
	{
		Node* temp=newNode(a[*i]);
		int val=*i;
		
		(*i)++;
		temp->left=createBST(a, i, min, a[val], n);
		temp->right=createBST(a, i, a[val], max, n);
		return temp;
	}
	
	return NULL;

}

 
Node* constructTree ( int pre[], int size )
{
	int i=0;
	return createBST(pre, &i, -1000, 1000, size);

}
 
 
void printInorder (Node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}
 
int main ()
{
    int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof( pre ) / sizeof( pre[0] );
 
    Node *root = constructTree(pre, size);
 
    printf("Inorder traversal of the constructed tree: \n");
    printInorder(root);
 
    return 0;
}
