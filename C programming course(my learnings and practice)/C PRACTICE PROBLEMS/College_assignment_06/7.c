//***Code for Q7***
#include <stdio.h>
int main()
{
    int n, a;
    printf("Enter the size of the array that you are going to create?\n");
    scanf("%d", &n);
    int arr[100];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("The entered array is :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Enter the number now:\n");
    scanf("%d", &a);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % a != 0)
        {
            for (int j = i; j < n; j++)
            {
                arr[j] = arr[j + 1];
            }
            n--;
            i--;
        }
    }
    printf("The modified array obtained after removing all the numbers which are not divisible by %d is :\n", a);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}