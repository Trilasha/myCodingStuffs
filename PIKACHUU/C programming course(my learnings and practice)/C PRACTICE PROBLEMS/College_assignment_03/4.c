//***Code for Q4***
#include <stdio.h>
int main()
{
    int n;
    printf("Enter the value of n:\n");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {7
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            printf("%d", j);
        }
        printf("\n");
    }
    for (int i = (n - 2); i >= 0; i--)
    {
        for (int j = 1; j <= 2 * i + 1; j++)
        {
            printf("%d", j);
        }
        printf("\n");
    }

    return 0;
}