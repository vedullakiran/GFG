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


node* MergeSorted(node* h1, node* h2)
{
	node* dummy=getNode(-1);
	node* head=dummy;
	
	while(h1 && h2)
	{
		if(h1->data<h2->data)
		{
			dummy->next=h1;
			h1=h1->next;
		}
		else
		{
			dummy->next=h2;
			h2=h2->next;
		}
		dummy=dummy->next;
	}
	
	while(h1)
	{
		dummy->next=h1;
		h1=h1->next;
		dummy=dummy->next;
	}

	while(h1)
	{
		dummy->next=h2;
		h2=h2->next;
		dummy=dummy->next;
	}
	return head->next;
}

int main()
{
	cout<<"Enter the first Sorted Array\n";
	node* h1=insertSortedArray();
	
	cout<<"Enter the Second Sorted Array\n";
	node* h2=insertSortedArray();
	
	node* newHead=MergeSorted(h1, h2);
	printList(newHead);
}
