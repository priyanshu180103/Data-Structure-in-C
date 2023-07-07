// Searching a node in a DLL 
#include<stdio.h>
#include<stdlib.h>
typedef struct stud
{
	struct stud *lptr;
	int info;
	struct stud *rptr;
}Node;
Node *start=NULL,*last=NULL;

int search(int value)
{
	Node *move;
	int k=0;
	move=start;
	while(move)
	{
		if(move->info==value)
		{
			
			k=1;
			break;
		}
		move=move->rptr;
	}
	if(k==1)
	{
		printf("\nIt is found in the DLL");
	}
	else
	{
		printf("\nIt is not found in the DLL");
	}
}
//Insertion at the End function
void add_end(int value)
{
Node *newptr=NULL,*tptr=NULL;
newptr=(Node*)malloc(sizeof(Node));
newptr->info=value;
newptr->lptr=NULL;
newptr->rptr=NULL;
if(start==NULL)
{
start=newptr;
}
else
{
tptr=start;
while(tptr->rptr!=NULL)
{
tptr=tptr->rptr;
}
tptr->rptr=newptr;
newptr->lptr=tptr;
last=newptr;
}
}
// Display forward move
void display_forward()
{
Node *tptr=start;
printf("\nDATA forward:\n");
while(tptr)
{
printf("->%d",tptr->info);
tptr=tptr->rptr;
}
}
// Display Backward move
void display_backward()
{
Node *tptr=last;
printf("\nDATA backward:\n");
while(tptr)
{
printf("->%d",tptr->info);
tptr=tptr->lptr;
}
}
// main function
int main()
{
char choice;
int value,i,pos;
while(1)
{
  	printf("\nDo you want to insert(y/n)?");
  	scanf("%c",&choice);
  	if(choice == 'y'||choice == 'Y')
	{
  	printf("\nEnter the info: ");
  	scanf("%d",&value);
	add_end(value);
  	fflush(stdin);
	}
	else
	{
	break;
	}
}

display_forward();
display_backward();
printf("\nEnter the value that you want to search: ");
scanf("%d",&value);
search(value);
return 0;
}

