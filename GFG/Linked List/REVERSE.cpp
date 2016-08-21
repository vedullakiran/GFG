#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

using namespace std;

struct node{
	int data;
	node* next;
};

node* getNode(int key)
{
	node* temp=(node*)malloc(sizeof(temp));
	temp->data=key;
	temp->next=NULL;
	return temp;
}

node* insertList()
{
	int n, num;
	cout<<"Enter the number of elements\n";
	cin>>n;
	
	node* head=NULL;
	node* temp=NULL;
	node* prev;
	for(int i=0; i<n; i++)
	{
		cin>>num;
		temp=getNode(num);
		if(head==NULL)
		{	
			head=temp;
			prev=temp;
			continue;
		}
		prev->next=temp;
		prev=prev->next;
	}
	return head;
}

void printList(node* head)
{
	node* temp=head;
	while(temp)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

void Reverse(node** head, node* prevN, node* currN)
{
	if(currN==NULL)
	{
		*head=prevN;
		return;
	}
	Reverse(head, currN, currN->next);
	currN->next=prevN;
}

int main()
{
	cout<<"Enter the first Sorted Array\n";
	node* head=insertList();
	Reverse(&head, NULL, head);
	printList(head);
}
