#include<stdio.h>
struct student
{
    char Name[50];
    int roll, m1,m2,m3,m4,m5;
}s[5];
int main()
{
     int i;
    printf("Enter the Information 5 stuednts");
    for(i=0;i<5;++i)
    {
        s[i].roll=i+1;
        printf("\n For Roll Number: %d \n",s[i].roll);
printf("Enter Name of Student:\n");
scanf("%s",&s[i].Name);
printf("Enter Marks of Student:\n");
printf(" Physics :");
scanf("%d",&s[i].m1);
printf(" Chemistry :");
scanf("%d",&s[i].m2);
printf(" Maths : ");
scanf("%d",&s[i].m3);
printf(" Biology :");
scanf("%d",&s[i].m4);
printf(" Computer :");
scanf("%d",&s[i].m5);
    }
printf("Displaying Information\n");
for(i=0;i<5;++i)
{
printf("\nRoll Number: %d\n",i+1);
printf("Name of Student:");
puts(s[i].Name);
printf("Marks of Student in 5 Subjects: \n");
printf(" Physics :%d \n",s[i].m1);
printf(" Chemistry :%d\n",s[i].m2);
printf(" Maths :%d\n",s[i].m3);
printf(" Biology :%d\n",s[i].m4);
printf(" Computer :%d\n",s[i].m5);
printf("\n");
}
}
