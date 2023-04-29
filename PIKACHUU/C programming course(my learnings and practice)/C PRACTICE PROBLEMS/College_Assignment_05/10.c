//***Code for Q10***
#include <stdio.h>
int main()
{
    int r, c;
    printf("Enter the number of rows of the matrix:\n");
    scanf("%d", &r);
    printf("Enter the number of columns of the matrix:\n");
    scanf("%d", &c);
    int arr[r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("The entered matrix is :\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    if(r==c)
    {
    printf("The corresponding upper triangular matrix is:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (j>=i)
            {
                printf("%d ",arr[i][j]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
    }
    else
    printf("Since the entered matrix is not a square matrix so upper triangular matrix not possible.");
    return 0;
}