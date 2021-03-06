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

void AlternateSplit(node* head, node** a, node** b)
{
	node* temp=NULL;
	while(1)
	{
		
		if(head)
		{
			temp=head->next;
			head->next=*a;
			*a=head;
			head=temp;
		}
		else	break;
		
		if(head)
		{
			temp=head->next;
			head->next=*b;
			*b=head;
			head=temp;
		}
		else	break;
	}	
}

int main()
{
	cout<<"Enter the List\n";
	node* head=insertList();
	node* a=NULL, *b=NULL;
	AlternateSplit(head, &a, &b);
	printList(a);
	printList(b);
}
