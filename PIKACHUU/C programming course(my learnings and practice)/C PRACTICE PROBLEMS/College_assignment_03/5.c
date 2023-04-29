//***Code for Q5***
#include <stdio.h>
int main()
{
    int n;
    printf("Enter the value of n:\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0 || i == (n - 1) || j == (n - 1) || (i == j) || i == (n - j - 1))
            {
                printf("*");
            }
            else
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}