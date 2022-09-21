//***Code for Q5***
#include <stdio.h>
int main()
{
    int arr[7] = {12, 14, 177, 289, 19, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("The given array is :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }printf("\n");
    int max;
    int i = 1;
    max = arr[0];
    while (i < n)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        else
            max;
        i++;
    }
    printf("The maximum element in the given array is : %d\n", max);
    int min;
    min = arr[0];
    int j = n - 1;//j=1 then j<n and j++ will also give the same result
    while (j > 0)
    {
        if (arr[j] < min)
        {
            min = arr[j];
        }
        else
            min;
        j--;
    }
    printf("The minimum element in the given array is : %d\n", min);
    return 0;}