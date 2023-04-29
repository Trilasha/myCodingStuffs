//***Code for Q5***
#include <stdio.h>
int sum_of_array(int *ptra, int *p)
{
    int sum = 0;
    for (int i = 0; i < *p; i++)
    {
        sum += *(ptra + i);
    }
    return sum;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("The given array is :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("The sum of all the elements of the given array is : %d", sum_of_array(arr, &n));
    return 0;
}