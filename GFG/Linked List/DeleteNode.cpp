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

node* insertSortedArray()
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

node* deleteNode(node* temp, node* head)
{
	if(head==NULL)
		return;

	if(temp==head)
	{
		temp=head;
		head=head->next;
		delete(temp);
		return;
	}
	
	node* ptr=head;
	while(ptr)
	{
		if(ptr==temp)
		{
			ptr->next=ptr->next->next;
			delete(temp);
		}
	}
}

int main()
{
	cout<<"Enter the List\n";
	node* h1=insertSortedArray();
	h1=deleteNode(head->next, h1);
	printList(h1);
	h1=deleteNode(h1, h1);
	printList(h1);
	h1=deleteNode(h1->next->next, h1);
	printList(h1);
}
