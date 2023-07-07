// Create a DLL by inserting a node at the beginning of the list
#include<stdio.h>
#include<stdlib.h>
typedef struct stud
{
	struct stud *lptr;
	int info;
	struct stud *rptr;
}Node;
Node *start=NULL,*last=NULL;
//Insertion at any Pos
void add_anypos(int value,int pos)
{
	int step=1;
Node *newp=NULL,*tptr=start,*tptr1=start;
newp=(Node*)malloc(sizeof(Node));
newp->info=value;
newp->lptr=NULL;
newp->rptr=NULL;
if(pos==1)
{
	newp->rptr=tptr;
	tptr->lptr=newp;
	//newp->lptr=NULL;
	start=newp;
}
else
{
while(step<pos-1)
{
	tptr=tptr->rptr;
	step++;
}
newp->lptr=tptr;
tptr=tptr->rptr;
newp->rptr=tptr;
newp->lptr->rptr=newp;
newp->rptr->lptr=newp;
}
while(tptr1->rptr!=NULL)
{
tptr1=tptr1->rptr;
}
last=tptr1;
}
//Insert at an end
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
fflush(stdin);
display_forward();
display_backward();

printf("\nDo you want to insert a node at any position of the list(y/n)?");
scanf("%c",&choice);
fflush(stdin);
if(choice == 'y'||choice == 'Y')
{
	printf("\nEnter the specific position: ");
	scanf("%d",&pos);
	printf("\nEnter the info: ");
  	scanf("%d",&value);
	add_anypos(value,pos);
}

display_forward();
display_backward();
return 0;
}
