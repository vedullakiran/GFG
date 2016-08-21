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

node* reverseMerge(node* h1, node* h2)
{
	node* lastNode=NULL, *temp=NULL;
	while(h1!=NULL && h2!=NULL)
	{
		if(h1->data<h2->data)
		{
			temp=h1;
			h1=h1->next;
		}
		else{
			temp=h2;
			h2=h2->next;
		}
		temp->next=lastNode;
		lastNode=temp;
	}
	
	while(h2!=NULL)
	{
		temp=h2;
		h2=h2->next;
		temp->next=lastNode;
		lastNode=temp;
	}
	
	while(h1!=NULL)
	{
		temp=h1;
		h1=h1->next;
		temp->next=lastNode;
		lastNode=temp;
	}
	
	return lastNode;
	
}

int main()
{
	cout<<"Enter the first Sorted Array\n";
	node* h1=insertSortedArray();
	
	cout<<"Enter the Second Sorted Array\n";
	node* h2=insertSortedArray();
	
	node* newHead=reverseMerge(h1, h2);
	printList(newHead);
}
