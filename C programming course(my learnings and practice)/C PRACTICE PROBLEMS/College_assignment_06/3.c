//***Code for Q3***
#include <stdio.h>
int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    printf("Suppose the first array(say arr1) is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    printf("Suppose the second array(say arr2) is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n");
    int(*ptr1)[n];
    ptr1 = &arr1;
    int(*ptr2)[n];
    ptr2 = &arr2;

    for (int i = 0; i < n; i++) // Copying the elements of arr1 to arr2
    {
        *(*ptr2 + i) = *(*ptr1 + i);
    }

    printf("After copying arr1 to arr2 using pointers, the array arr2 now looks like this:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(*ptr2 + i));
    }

    return 0;
}