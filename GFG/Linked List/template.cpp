#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

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

int main()
{
	
}
