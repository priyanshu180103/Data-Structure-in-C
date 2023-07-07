// This program will help us to Create a Singly Linked List,Traverse it.
// Also this program will help us to insert a node at the end of the list.
#include<stdio.h>
#include<stdlib.h>
typedef struct stud
{
	int info;
	struct stud *link;
}Node;
Node *start=NULL;
void add_node(int);
void display();
int main()
{
 int value,count=0;
 char choice;
 while(1)
{
  	printf("Do you want to insert(y/n)?");
  	scanf("%c",&choice);
  	if(choice == 'y')
	{
  	printf("\nEnter the info:");
  	scanf("%d",&value);
	add_node(value);
  	fflush(stdin);
	}
	else
	{
	break;
	}
}
 printf("\nThe linked list is");
 display();

return 0;
}
void add_node(int data)
{
	Node *newptr=NULL,*ptr;
	newptr=(Node*)malloc(sizeof(Node));//for a node
	newptr->info=data;
	newptr->link=NULL;
	if(start==NULL)
	{
		start=newptr;
	}
	else
	{
		ptr=start;
	
	while(ptr->link!=NULL)
	{
		ptr=ptr->link;
	}
	ptr->link=newptr;
}
}
void display()//Traverse the SLL
{
	Node *ptr;
	ptr=start;
	printf("->");
	while(ptr)
	{
		printf("(%u)%d(%u)->",ptr,ptr->info,ptr->link);
		ptr=ptr->link;
	}
	printf("NULL");
}


