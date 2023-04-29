//***Code for Q3***
#include <stdio.h>
int main()
{
    int arr[] = {1, 3, 4, 5, 6, 5, 6, 4, 6, 7, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("The given array of integers is : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("The first repeating element in the above array is: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                printf("%d ", arr[i]);
                goto end;
            }
        }
    }

    return 0;
end:
    printf("\n");}
