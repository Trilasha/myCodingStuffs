//***Code for Q1***
#include <stdio.h>
void rotate(int arr[], int n)
{
    int a = arr[n - 1];
    for (int i = n - 1; i > 0; i--)//cannot obtain the output if started the loop from first
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = a;
}
int main()
{
    int arr[7] = {12, 14, 15, 16, 17, 18, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("The given array is : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    rotate(arr, n);
    printf("The array formed after rotating by one :\n");
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
// The same thing can be done in C++ using the swap in-built funtion