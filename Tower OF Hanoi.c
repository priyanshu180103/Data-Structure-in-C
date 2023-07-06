/*Program to calculate time taken to move the given no of disc, when 1s is the time taken to 
move each disc between the towers.*/
#include<stdio.h>
int c1,c2;
void TowerOfHanoi(int N, char S, char A, char D)
{ 
if(N==1)
{
    printf("Move from tower %c to tower %c\n",S,D);
c1++;
}
else
{
    TowerOfHanoi(N-1,S,D,A);
   printf("Move from tower %c to tower %c\n",S,D);
    TowerOfHanoi(N-1,A,S,D);
c2++;
}
}
int main()
{
int N;
printf("Enter the No of Rings\n");    
scanf("%d",&N);
TowerOfHanoi(N,'s','a','d');
int t=1,sec,min,hr,day,yr;
sec=t*(c1+c2);
min=sec/60;
hr=min/60;
day=hr/24;
yr=day/365;
printf("\nThe Time Taken to Move %d Disc\n",N);
printf("\nSecond:%d\nMinutes:%d\nHours:%d\nDays:%d\nYears:%d\n",sec,min,hr,day,yr);
}


