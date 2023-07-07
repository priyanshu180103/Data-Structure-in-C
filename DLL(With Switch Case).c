#include<stdio.h>
#include<stdlib.h>
struct node  
{  
    struct node *prev;  
    struct node *next;  
    int data;  
};  
struct node *head;

void add_beg();
void add_end();
void add_anypos();
void delete_beg();
void delete_end();
void delete_anypos();
void display();
void search();

void main()
{
    int ch=0;
    while(ch !=9 )   
    {  
        printf("\nChoose one option from the following list ...\n");    
        printf("\n1.Insert in the Begining\n2.Insert at the End\n3.Insert at Any Position\n4.Delete at the Begining\n5.Delete at the End\n6.Delete at Any Specific Position\n7.Search in the list\n8.Show\n9.Exit");  
        printf("\nEnter your choice?\n");         
        scanf("\n%d",&ch);  
        switch(ch)
        {  
            case 1: 
            add_beg(); 
            break;        
            case 2: 
            add_end();      
            break;  
            case 3:
            add_anypos();
            break;  
            case 4: 
            delete_beg();    
            break;  
            case 5: 
            delete_end();        
            break;  
            case 6:
            delete_anypos();
			case 7:
			search();
			case 8:
			display();
            break;
			case 9:
			exit(0);
			break;
			default:  
            printf("Please enter valid choice..");  
        }  
	}
}
void add_beg()
{
 struct node *ptr;   
 int item;  
 ptr = (struct node *)malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\nOVERFLOW");  
   }  
   else  
   {  
    printf("\nEnter Item value ");  
    scanf("%d",&item);  
      
   if(head==NULL)  
   {  
       ptr->next = NULL;  
       ptr->prev=NULL;  
       ptr->data=item;  
       head=ptr;  
   }  
   else   
   {  
       ptr->data=item;  
       ptr->prev=NULL;  
       ptr->next = head;  
       head->prev=ptr;  
       head=ptr;  
   }  
   printf("\nNode inserted\n");  
   }
}  
     
void add_end()
{
struct node *ptr,*temp;  
   int item;  
   ptr = (struct node *) malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\nOVERFLOW");  
   }  
   else  
   {  
       printf("\nEnter value ");  
       scanf("%d",&item);  
        ptr->data=item;  
       if(head == NULL)  
       {  
           ptr->next = NULL;  
           ptr->prev = NULL;  
           head = ptr;  
       }  
       else  
       {  
          temp = head;  
          while(temp->next!=NULL)  
          {  
              temp = temp->next;  
          }  
          temp->next = ptr;  
          ptr ->prev=temp;  
          ptr->next = NULL;  
          }  
             
       }  
     printf("\nNode inserted\n");
}

void add_anypos()
{
	struct node *ptr,*temp;  
   int item,loc,i;  
   ptr = (struct node *)malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\n OVERFLOW");  
   }  
   else  
   {  
       temp=head;  
       printf("Enter the location ");  
       scanf("%d",&loc);  
       for(i=0;i<loc;i++)  
       {  
           temp = temp->next;  
           if(temp == NULL)  
           {  
               printf("\n There are less than %d elements", loc);  
               return;  
           }  
       }  
       printf("Enter value ");  
       scanf("%d",&item);  
       ptr->data = item;  
       ptr->next = temp->next;  
       ptr -> prev = temp;  
       temp->next = ptr;  
       temp->next->prev=ptr;  
       printf("\nNode inserted\n");  
   }  
}

void delete_beg()
{
  struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\n UNDERFLOW");  
    }  
    else if(head->next == NULL)  
    {  
        head = NULL;   
        free(head);  
        printf("\nNode deleted\n");  
    }  
    else  
    {  
        ptr = head;  
        head = head -> next;  
        head -> prev = NULL;  
        free(ptr);  
        printf("\nNode deleted\n");  
    }  
}

void delete_end()
{
 struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\n UNDERFLOW");  
    }  
    else if(head->next == NULL)  
    {  
        head = NULL;   
        free(head);   
        printf("\nNode deleted\n");  
    }  
    else   
    {  
        ptr = head;   
        if(ptr->next != NULL)  
        {  
            ptr = ptr -> next;   
        }  
        ptr -> prev -> next = NULL;   
        free(ptr);  
        printf("\nNode deleted\n");  
    }  
}

void delete_anypos()
{
	struct node *ptr, *temp;  
    int val;  
    printf("\n Enter the data after which the node is to be deleted : \n");  
    scanf("%d", &val);  
    ptr = head;  
    while(ptr -> data != val)  
    ptr = ptr -> next;  
    if(ptr -> next == NULL)  
    {  
        printf("\nCan't delete\n");  
    }  
    else if(ptr -> next -> next == NULL)  
    {  
        ptr ->next = NULL;  
    }  
    else  
    {   
        temp = ptr -> next;  
        ptr -> next = temp -> next;  
        temp -> next -> prev = ptr;  
        free(temp);  
        printf("\nNode deleted\n");  
    }     
}
void search()
{
	 struct node *ptr;  
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
            if(ptr->data == item)  
            {  
                printf("\nItem found at location %d ",i+1);  
                flag=0;  
                break;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
        }  
        if(flag==1)  
        {  
            printf("\nItem not found\n");  
        }  
    }     
}

void display()
{
struct node *ptr;  
    printf("\n The Doubly Linked List:\n");  
    ptr = head;  
    while(ptr != NULL)  
    {  
        printf("%d->",ptr->data);  
        ptr=ptr->next;  
	}
}
