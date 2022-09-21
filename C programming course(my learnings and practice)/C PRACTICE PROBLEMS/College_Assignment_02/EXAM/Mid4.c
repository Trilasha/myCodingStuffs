#include <stdio.h>
int main()
{
  int a,n,arr[10];
printf("Enter the value of n\n");
scanf("%d", &n);
printf("Enter the value of the elements\n");
for (int i = 0; i < n; i++)
{
    scanf("%d", &arr[i]);
}
for ( int i = 0; i < n; i++)
{
    for (int j = i+1; j < n;j++)
    {
        if (arr[i]<arr[j]) //For ascending >
        {
            a=arr[i];
            arr[i]=arr[j];
            arr[j]=a;

        }
        
    }
    
}

printf("The numbers arranged in the descending order are:\n");
for (int  i = 0; i < n; i++)
{
printf("%d\n",arr[i]);
}


    return 0;
}