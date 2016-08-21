#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;


struct node
{
    int data;
    struct node* next;
};
 
void push(struct node** head_ref, int new_data)
{
    	struct node* new_node = (struct node*) malloc(sizeof(struct node));
 
    	new_node->data  = new_data;
 
    	new_node->next = (*head_ref);
 
    	(*head_ref)    = new_node;
}
 
bool detectLoop(node* head)
{
	if(head==NULL)
		return 0;
	node* slow=head, *fast=head;
	while(fast && fast->next )
	{
		slow=slow->next;
		fast=fast->next->next;
		if( slow==fast)
			return false;
	}
	return true;
}
 
int main()
{
    	struct node* head = NULL;
 
    	push(&head, 20);
    	push(&head, 4);
    	//push(&head, 15);
    	push(&head, 10);
 	
    	//head->next->next->next = head;
	
	if(!detectLoop(head))
		cout<<"Loop Exist\n";
	else		 cout<<"Loop doesn't Exist\n";
    	return 0;
}
