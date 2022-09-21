//***Code for Q7***
#include <stdio.h>
int main()
{
   //int k,temp;
   //int arr[] = {12,31,16,71,81,6,4,5,9};
   //int n = sizeof(arr) / sizeof(arr[0]);
   //printf("The given array is :\n");    //Doing for an array with non-repeating elements
   //for (int i = 0; i < n; i++)
   //{ printf("%d ",arr[i]);
   //} printf("\n");
   //printf("Enter the value of K:\n");
   //scanf("%d",&k);
   //for (int i = 0; i <n; i++)           //sorting the given array in ascending order
   //{ for (int j = i+1; j < n; j++)
   //   { if (arr[i]>arr[j])
   //       {   temp=arr[i];
   //           arr[i]=arr[j];
   //           arr[j]=temp;
   //       }}}
   //printf("The %dth smallest value in the given array is : %d\n",k,arr[k-1]);
   //for (int i = 0; i <n; i++)           //sorting the given array in descending order
   //{for (int j = i+1; j < n; j++)
   //   {if (arr[i]<arr[j])
   //       {
   //           temp=arr[i];
   //           arr[i]=arr[j];
   //           arr[j]=temp;
   //       }}}
   //printf("The %dth largest value in the given array is : %d",k,arr[k-1]);


//The code that will apply to arrays with boh repeating and non-repeating elements
int arr[100];
int n;
scanf("%d",&n);
for (int i = 0; i < n; i++)
{
    scanf("%d",&arr[i]);
}
for (int i = 0; i < n; i++)
{
   printf("%d ",arr[i]);
}
printf("\n");
//to print the array without any repeatng element
for (int i = 0; i < n; i++)
{
    for (int j = i+1; j < n; j++)
    {
        if (arr[i]==arr[j])
        {
            for (int k = 0; k < n-1; k++)
            {
               arr[k]=arr[k+1];
            }
            n--;
           
        }
       
    }
    
}
for (int i = 0; i < n; i++)
{
    printf("%d ",arr[i]);
}

    return 0;}