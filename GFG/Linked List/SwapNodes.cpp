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

void SwapNodes(int X, int Y, node** head)
{
	if(X==Y)
		return;
		
	node* prevX=NULL, *currX=*head;
	while(currX && currX->data!=X)
	{
		prevX=currX;
		currX=currX->next;
	}

	node* prevY=NULL, *currY=*head;
	while(currY && currY->data!=Y)
	{
		prevY=currY;
		currY=currY->next;
	}
	
	if(currY && currX)
	{
		
		if(prevX==NULL)
			*head=currY;
		else
			prevX->next=currY;
		
		if(prevY==NULL)
			*head=currX;
		else
			prevY->next=currX;
			
		node* temp=currY->next;
		currY->next=currX->next;
		currX->next=temp;
		
	}
}

int main()
{
	cout<<"Enter the List\n";
	node* head=insertList();
	int X, Y;
	cout<<"Enter the two numbers to be swaped\n";
	cin>>X>>Y;
	SwapNodes(X, Y, &head);
	printList(head);
}
