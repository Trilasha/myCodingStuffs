#include <stdio.h>
int main()
{
    int y,i,j,x;
    printf("Enter the no. of rows:");
    scanf("%d",&y);
    for ( i = 1; i <=y; i++)
    {
        for (x = 1; x <y-i; x++)
        {
           printf(" ");
        }
        for (j = 0; j<2*i-1; j++)
        {
            printf("%d",i);
        }
        printf("\n");
    }

    return 0;
}