//Delete a node at a specific position of a DLL
#include<stdio.h>
#include<stdlib.h>
typedef struct stud
{
	struct stud *lptr;
	int info;
	struct stud *rptr;
}Node;
Node *start=NULL,*last=NULL;
void delete_anypos(int total)
{
	int position, steps;
	Node *move;
	printf("\n Enter the position of deletion of Node <= %d\n",total);
	scanf("%d",&position);
	if(position<1 || position >total)
	{
		printf("\nInvalid position inputted\n");
		exit(0);
	}
	if(position==1)
	{
		if(start==last)// if there is only one Node
		{
			free(start);
			start=last=NULL;
		}
		else
		{
		 // When the list has two or more Nodes
		 move=start;
		 start=start->rptr;
		 start->lptr=NULL;
		 free(move);	
		}
	}
	else
	{
		// search for the Node to be deleted
		steps=1;
		move=start;
		while(steps<position)
		{
			move=move->rptr;
			steps++;
		}
		
		//if right most Node is to be deleted
		if(move==last)
		{
			last=last->lptr;
			last->rptr=NULL;
		}
		else
		{
			(move->lptr)->rptr=move->rptr;
			(move->rptr)->lptr=move->lptr;
		}
		free(move);
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


int main()
{
char choice;
int value,i,pos,totalnode=0;
while(1)
{
  	printf("\nDo you want to insert(y/n)?");
  	scanf("%c",&choice);
  	if(choice == 'y'||choice == 'Y')
	{
  	printf("\nEnter the info: ");
  	scanf("%d",&value);
  	add_end(value);
	totalnode++;
  	fflush(stdin);
	}
	else
	{
	break;
	}
}
fflush(stdin);
display_forward();
display_backward();

printf("\nDo you want to delete a node at any position of the list(y/n)?");
scanf("%c",&choice);
fflush(stdin);
if(choice == 'y'||choice == 'Y')
{
	delete_anypos(totalnode);
}

display_forward();
display_backward();
return 0;
}
