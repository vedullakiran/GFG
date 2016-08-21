
// C++ program to construct a Binary Tree from parent array
#include<bits/stdc++.h>
using namespace std;
 
// A tree node
struct Node
{
    int key;
    struct Node *left, *right;
};
 
// Utility function to create new Node
Node *newNode(int key)
{
    Node *temp = new Node;
    temp->key  = key;
    temp->left  = temp->right = NULL;
    return (temp);
}
 
 
 Node* createTree(int  parent[], int n)
{
	int i;
	Node* hash[n];
	for(int i=0; i<n; i++)
		hash[i]=newNode(i);
	
	Node* root=NULL;
	
	for(i=0; i<n; i++)
	{
		if(parent[i]==-1)
			root=hash[i];
		else if(hash[parent[i]]->left==NULL)
			hash[parent[i]]->left=hash[i];
		else
			hash[parent[i]]->right=hash[i];
	}
	
	return root;
}



 
//For adding new line in a program
inline void newLine(){
    cout << "\n";
}
 
// Utility function to do inorder traversal
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}
 
int main()
{
    int parent[] =  {-1};
    int n = sizeof parent / sizeof parent[0];
    Node *root = createTree(parent, n);
    cout << "Inorder Traversal of constructed tree\n";
    inorder(root);
    newLine();
}
