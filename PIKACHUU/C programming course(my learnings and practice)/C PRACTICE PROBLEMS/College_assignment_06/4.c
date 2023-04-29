//***Code for Q4***
#include <stdio.h>
int main()
{
    int arr[] = {12, 16, 61, 9, 21, 7, 28};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("The given array is :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int(*ptr)[n];
    ptr = &arr;
    printf("The above array sorted in the ascending order:\n");
    for (int i = 0; i < n; i++)
    {for (int j = i + 1; j < n; j++)
        {if (*(*ptr + i) > *(*ptr + j))
            {
                int temp;
                temp = *(*ptr + i);
                *(*ptr + i) = *(*ptr + j);
                *(*ptr + j) = temp;
            }}}
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(*ptr + i));
    }
    printf("\n");
    printf("The above array sorted in the descending order:\n");

    for (int i = 0; i < n; i++)
    {for (int j = i + 1; j < n; j++)
        {if (*(*ptr + i) < *(*ptr + j))
            {
                int temp;
                temp = *(*ptr + i);
                *(*ptr + i) = *(*ptr + j);
                *(*ptr + j) = temp;
            }}}
for (int i = 0; i < n; i++)
    {
         printf("%d ", *(*ptr + i));
    }
    return 0;}