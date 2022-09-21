#include <stdio.h>
int main()
{
    int n,arr[n],k,i,j;
    printf("Enter the number of elements that you want in an array\n");
    scanf("%d", &n);
    printf("Set the upper limit of the element range starting from 0\n");
    scanf("%d",&k);
    printf("Enter the value of the elements keeping in mind its range from 0 to %d\n",k);
    for ( i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int count[k];
    printf("The entered numbers are:\n");  
    for ( i = 0; i < n; i++)
    {
       printf("%d\n",arr[i]);
    }
    for (int i = 0; i <k; i++)
    {
      for (int j = 0; j < n; i++)
      {
         if (i==arr[j])
         {
            count[i]++;
         }
         
      }
      
    }
    
   for (int i = 0; i < k; i++)
   {
       printf("The total occurences of %d is %d\n",i,count[i]);
   }
   
    
    return 0;
}