//***Code for Q4***
#include <stdio.h>
int main()
{
    int arr[] = {3, 4, 5, 3, 6, 6, 7, 4, 4, 5, 9};
    int count;
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("The given array of integers is : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("The first non-repeating element in the above array is: \n");

    for (int i = 0; i < n; i++)
    {
        count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] != arr[j])
            {
                count++;
            }
        }
        if (count == n - 1)
        {
            printf("%d", arr[i]);
            goto end;
        }
    }

end:
    printf("\n");
    return 0;
}
