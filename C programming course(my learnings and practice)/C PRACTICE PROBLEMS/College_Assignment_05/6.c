//***Code for Q6***-->MODIFIED
#include <stdio.h>
void reverse(int arr[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        int temp;
        temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("The given array is :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
   //reverse(arr, n);
   printf("The reversed array is : \n");
   //for (int i = 0; i < n; i++)
   //{
   //    printf("%d ", arr[i]);
   //}
   

   //Trying out another way
   for (int i = n-1; i>=0; --i)
   {
      printf("%d ",arr[i]);
   }
   

    return 0;
}