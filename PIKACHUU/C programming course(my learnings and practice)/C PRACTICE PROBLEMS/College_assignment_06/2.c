//***Code for Q2***
#include <stdio.h>
int main()
{
    int n;
    printf("How many numbers do you want to enter?\n");
    scanf("%d", &n);
    printf("Enter the numbers now:\n");
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int(*ptr)[n];
    ptr = &arr;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (*(*ptr + i) > *(*ptr + j))
            {
                int temp;
                temp = *(*ptr + i);
                *(*ptr + i) = *(*ptr + j);
                *(*ptr + j) = temp;
            }
        }
    }
    printf("The smallest entered number is : %d", *(*ptr));
    return 0;
}