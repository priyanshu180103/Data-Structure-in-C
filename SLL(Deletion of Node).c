//This program will help us to Delete a Node in a specific position of a SLL.
//This program will help us to Delete a Node at the beginning of a SLL.
#include<stdio.h>
typedef struct stud
{
	int info;
	struct stud *link;
}Node;
Node *start=NULL;
void add_node(int);
void display();
void del_beg();
void del_end();
void del_anypos(int);
int main()
{
 int value,count=0,pos=0;
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
 printf("\n Enter the position");
 scanf("%d",&pos);
 del_anypos(pos);
 printf("\nAfter deleting a node at any pos, The linked list is");
 display();

 del_beg();
 printf("\nAfter deleting at the beginning, The linked list is");
 display();
 
 del_end();
 printf("\nAfter deleting at end, The linked list is");
 display();
return 0;
}
void add_node(int data)
{
	Node *newptr=NULL,*ptr;
	newptr=(Node*)malloc(sizeof(Node));
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
void display()
{
	Node *ptr;
	ptr=start;
	printf("->");
	while(ptr)
	{
		printf("%d->",ptr->info);
		ptr=ptr->link;
	}
	printf("NULL");
}
void del_end()
{
	Node *tptr=start,*temp=NULL;
	while(tptr->link!=NULL)
	{
		temp=tptr;
		tptr=tptr->link;
	}
	temp->link=NULL;
	free(tptr);
}
//Deletion at anypos function
void del_anypos(int pos1)
{
	int step=1;
	Node *tptr=start,*temp;
	while(step<pos1)
	{
		temp=tptr;
		tptr=tptr->link;
		step++;
	}
	temp->link=tptr->link;
	free(tptr);
}
//Deletion at beg function
void del_beg()
{
	Node *temp=start;
	start=start->link;
	free(temp);
}
