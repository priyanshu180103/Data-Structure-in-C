#include<stdio.h>
#include<stdlib.h>
typedef struct stud
{
    int info;
    struct stud *link;
}Node;
Node *start=NULL;
void add_node(int);
void search();
void insert();
void delete();
void display();

int main()
{
 int value,count=0;
 char choice;
 while(1)
{
  	printf("Do you want to insert(y/n)?");
  	scanf("%c",&choice);
  	if(choice == 'y'||choice=='Y')
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
 
 int ch=0;
    while(ch != 5)   
    {  
        printf("\nChoose one option from the following list ...\n");    
        printf("\n1.Search value in List\n2.Insert value in between the list\n3.Delete a spechific value\n4.Show\n5.Exit\n");  
        printf("\nEnter your choice?\n");         
        scanf("\n%d",&ch);  
        switch(ch)
        {  
            case 1:  
            search();      
            break;  
            case 2:  
			insert();         
            break;  
            case 3:  
            delete();
            break;  
            case 4:  
            printf("\nThe linked list is");
            display();
			exit(0);
            break;  
            case 5:  
            exit(0);  
            break;  
            default:  
            printf("Please enter valid choice..");  
        }  
	}
 
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
void search()  
{  
     Node *ptr,*head=start;  
	ptr=(Node*)malloc(sizeof(Node));
	int item,i=0,flag;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("\nEnter item which you want to search?\n");   
        scanf("%d",&item);  
        while (ptr!=NULL)  
        {  
            if(ptr->info == item)  
            {  
                printf("item found at location %d ",i+1);  
                flag=0;  
            break;
			}   
            else  
            {  
                flag=1;  
            } 
            i++;  
            ptr = ptr -> link;  
        }  
        if(flag==1)  
        {  
            printf("Item not found\n");  
        }  
    }   
}




void insert()
{
	int value,pos;
	printf("\n Enter the value");
 scanf("%d",&value);
 printf("\n Enter the position");
 scanf("%d",&pos);
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


void delete()
{
	int pos1;
	printf("\n Enter the position");
 scanf("%d",&pos1);
	
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




void display()
{
	Node *ptr;
	ptr=start;
	printf("->");
	while(ptr)
	{
		printf(" %d  ",ptr->info);
		ptr=ptr->link;
	}
	
}
