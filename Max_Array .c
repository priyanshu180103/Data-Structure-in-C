#include <stdio.h>
 
 int max_array(int a[],int n)
 {
 	int max,i;
 	max=a[0];
    for(i=1; i<n; i++)
    {
		   if(max<a[i])
		    max=a[i];       
    }
    
    printf("\nmaximum no in array is : %d",max);
 }
int main()
{
    int a[1000],i,n;
   
    printf("Enter size of the array :\n ");
    scanf("%d", &n);
 
    printf("Enter elements in array :\n ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    max_array(a,n);
    
}
