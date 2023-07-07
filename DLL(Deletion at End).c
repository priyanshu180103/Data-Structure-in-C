//Delete a node at the end of a DLL
#include<stdio.h>
#include<stdlib.h>
typedef struct stud
{
	struct stud *lptr;
	int info;
	struct stud *rptr;
}Node;
Node *start=NULL,*last=NULL;
void delete_end()
{
 Node *move,*cpt;
 move=start;
 while(move->rptr!=NULL)
		{
			cpt=move;
			move=move->rptr;
			
		}
 cpt->rptr=NULL;
 last=cpt;	
 free(move);
 printf("\n Deletion is done")	;
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

printf("\nDo you want to delete a node of the list(y/n)?");
scanf("%c",&choice);
fflush(stdin);
if(choice == 'y'||choice == 'Y')
{
	delete_end();
}

display_forward();
display_backward();
return 0;
}
