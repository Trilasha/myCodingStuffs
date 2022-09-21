//***Code for Q9***
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *ptr;
    int n;
    printf("Enter the size of the array you want to create:\n");
scanf("%d",&n);
ptr=(int*)malloc(n*sizeof(int));
printf("Enter the array elements:\n");
for (int i = 0; i < n; i++)
{
   scanf("%d",&ptr[i]);
}
printf("The entered array is:\n");
for (int i = 0; i < n; i++)
{
    printf("%d ",ptr[i]);
}
printf("\n");
for (int i = 0; i < n/2; i++)
{
   int temp;
   temp=ptr[i];
   ptr[i]=ptr[n-i-1];
   ptr[n-i-1]=temp;
}
printf("The reversed array is : \n");
for (int i = 0; i < n; i++)
{
    printf("%d ",ptr[i]);
}
free(ptr);
    return 0;
}