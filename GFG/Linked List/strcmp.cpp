#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string>

using namespace std;

struct node{
	char data;
	node* next;
};

node* getNode(char key)
{
	node* temp=(node*)malloc(sizeof(temp));
	temp->data=key;
	temp->next=NULL;
	return temp;
}

node* insertString()
{
	string s;
	cout<<"Enter the string\n";
	cin>>s;
	
	node* head=getNode(s[0]);
	node* temp=head;
	
	for(int i=1; i<s.length(); i++)
	{
		temp->next=getNode(s[i]);
		temp=temp->next;
	}
	
	temp=head;
	while(temp)
	{
		cout<<temp->data;
		temp=temp->next;
	}
	cout<<endl;
	return head;
}

int strcmp(node* h1, node* h2)
{
	while(h1!=NULL && h2!=NULL)
	{
		if(h1->data > h2->data)
			return 1;
		else if(h1->data < h2->data)
			return -1;
		//cout<<h1->data<<" "<<h2->data<<endl;
		h1=h1->next;
		h2=h2->next;
	}
	if(h1==NULL && h2==NULL)
		return 0;
	else if(h1==NULL)
		return 1;
	else return -1;
}

int main()
{
	node* h1=insertString();
	node* h2=insertString();
	
	if(strcmp(h1, h2)==0)
		cout<<"equal\n";
	else if(strcmp(h1, h2)==1)
		cout<<"String1 is lexiographically larger\n";
	else
		cout<<"String2 is lexiographically larger\n";
}
