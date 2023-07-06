#include<stdio.h>
#include<stdlib.h>
#define size 10
int c_queue[size],front,rear;
void addc_queue();
void delc_queue();
void traverse();
int main(){
 int ch;
 front=rear=-1;
 while(1){
 printf("\n1.Create.\n");
 printf("2.Display.\n");
 printf("3.Delete.\n");
 printf("4.Exit\n");
 printf("Enter Your Choice:");
 scanf("%d",&ch);
 switch(ch){
 case 1:addc_queue();
 break;
 case 2:traverse();
 break;
 case 3:delc_queue();
 break;
 default: exit(0);
 }
 }
 return 0;
}
void addc_queue(){
 int val;
 if(front==(rear+1)%size){
 printf("\n=====Queue Is Full=====\n");
 return;
 }
 printf("Enter Any Value: ");
 scanf("%d",&val);
 if(rear==-1){
 rear=front=0;
 }
 else{
 rear=(rear+1)%size;
 }
 c_queue[rear]=val;
}
void delc_queue(){
 if(front==-1){
 printf("\n=====Queue Is Empty=====\n");
 return;
 }
 printf("Deleted Data Is: %d",c_queue[front]);
 if(front==rear){
 front=rear=-1;
 }
 else{
 front=(front+1)%size;
 }
}
void traverse(){
 int i;
 if(rear==-1){
 printf("\n=====Nothing To Dispaly=====\n");
 return;
 }
 i=front;
 do{
 printf("%d\t",c_queue[i]);
 i=(i+1)%size;
 }
 while(i!=(rear+1)%size);
}
