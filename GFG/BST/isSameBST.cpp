#include <stdio.h>
#include<stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
 
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

bool isSameBSTUtil(int a[], int b[], int l1, int l2, int mini, int maxi, int n)
{
	int i, j;
	for(i=l1; i<n; i++)
		if(a[i]<maxi && a[i]>mini)
			break;
	
	for(j=l2; j<n; j++)
		if(b[j]<maxi && b[j]>mini)
			break;

	if(a[i]==b[j])
		return isSameBSTUtil(a, b, i, j, mini, a[i], n) && isSameBSTUtil(a, b, i, j, a[i],  maxi, n);
		
	
	if(i==n && j==n)
		return true;
	
	return false;
}

bool isSameBST(int a[], int b[], int n)
{
	return isSameBSTUtil(a, b, 0, 0, -1000, 1000, n);
}

int main()
{
	   int a[] = {8, 3, 6, 1, 4, 7, 10, 9, 13};
	   int b[] = {8, 10, 14, 3, 6, 4, 1, 7, 13};
	   int n=sizeof(a)/sizeof(a[0]);
	   printf("%s\n", isSameBST(a, b, n)?"BSTs are same":"BSTs not same");
	   return 0;
}

