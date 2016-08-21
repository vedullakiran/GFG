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

void swap(int *a, int* b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void pairWiseSwap(node* head)
{
	while(head && head->next)
	{
		swap(&head->data, &head->next->data);
		head=head->next->next;
	}
}

int main()
{
	cout<<"Enter the List\n";
	node* head=insertList();
	pairWiseSwap(head);
	printList(head);
}
