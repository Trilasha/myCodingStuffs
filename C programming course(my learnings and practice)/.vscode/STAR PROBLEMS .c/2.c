#include <stdio.h>
int main()
{
    //problem 2
    int i, j;
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            if (j >= 6 - i)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
        return 0;
    }