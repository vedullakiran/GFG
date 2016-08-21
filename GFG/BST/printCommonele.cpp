#include<iostream>
#include<stack>
#include <stdio.h>
using namespace std;

// A BST node
struct Node
{
    int key;
    struct Node *left, *right;
};

// A utility function to create a new node
Node *newNode(int ele)
{
    Node *temp = new Node;
    temp->key = ele;
    temp->left = temp->right = NULL;
    return temp;
}



void printCommon(Node* root1, Node* root2)
{
	if(root1==NULL || root2==NULL)
		return;
		
	stack<Node*> S1, S2;
	
	
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
		
		if( S1.top()->key==S2.top()->key )
		{
			root1=S1.top();
			printf("%d ", root1->key);
			root2=S2.top();
			root1=root1->right;
			root2=root2->right;
			S1.pop();
		}
		else if(S1.top()->key<S2.top()->key)
		{
			root1=S1.top();
			root1=root1->right;
			S1.pop();
		}
		else
		{
			root2=S2.top();
			root2=root2->right;
			S2.pop();
		}
		
	}
}





void inorder(struct Node *root)
{
    if (root)
    {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}

struct Node* insert(struct Node* node, int key)
{
    if (node == NULL) return newNode(key);

    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

int main()
{
    Node *root1 = NULL;
    root1 = insert(root1, 2);
    root1 = insert(root1, 1);
    Node *root2 = NULL;
    root2 = insert(root2, 1);
    root2 = insert(root2, 2);
    cout << "Tree 1 : ";
    inorder(root1);
    cout << endl;

    cout << "Tree 2 : ";
    inorder(root2);
    cout<<endl;
    printCommon(root1, root2);

    return 0;
}
