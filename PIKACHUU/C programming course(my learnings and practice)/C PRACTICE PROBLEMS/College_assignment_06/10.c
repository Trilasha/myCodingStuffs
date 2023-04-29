//***Code for Q10***
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *ptr;
    int n;
    printf("Enter the size of the array you want to create:\n");
    scanf("%d",&n);
    ptr = (int*)calloc(n, sizeof(int));
    printf("Enter the array elements:\n");
for (int i = 0; i < n; i++)
{
   scanf("%d",&ptr[i]);
}
printf("The entered array is:\n");
for (int i = 0; i < n; i++)
    printf("%d ",ptr[i]);
printf("\n");
int max=ptr[0];
for (int i = 0; i < n; i++)
{
    if (ptr[i]>max)
    { max=ptr[i];}}
printf("The largest element in the given array is : %d",max);
free(ptr);
    return 0;}