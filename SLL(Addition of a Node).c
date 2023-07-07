//This program will help us to Insert a Node in a specific position of a SLL.
//This program will help us to Insert a Node at the beginning of a SLL.
#include<stdio.h>
typedef struct stud
{
    int info;
    struct stud *link;
}Node;
Node *start=NULL;
void add_node(int);
void display();
void add_anypos(int ,int);
void add_beg(int);
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
 printf("\n Enter the value");
 scanf("%d",&value);
 printf("\n Enter the position");
 scanf("%d",&pos);
 add_anypos(value,pos);
 printf("\nAfter inserting The linked list is");
 display();
 printf("\n Enter the value");
 scanf("%d",&value);
 add_beg(value);
 printf("\nAfter inserting at the beginning The linked list is");
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
void add_anypos(int value,int pos)
{
	Node *newp=NULL,*tptr=start;
	int steps=1;
	newp=(Node*)malloc(sizeof(Node));
	newp->info=value;
	newp->link=NULL;
	while(steps<pos-1)
	{
		tptr=tptr->link;
		steps++;
	}
	if(pos==1)
	{
		newp->link=start;
		tptr->link=newp;
	}
	else
	{
		newp->link=tptr->link;
		tptr->link=newp;
	}
}
void add_beg(int value)
{
	Node *newp=NULL;
	newp=(Node*)malloc(sizeof(Node));
	newp->info=value;
	newp->link=NULL;
	if(start==NULL)
	{
		start=newp;
	}
	else
	{
		newp->link=start;
		start=newp;
		
	}
}
