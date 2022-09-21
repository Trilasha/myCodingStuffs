//***Code for Q8***
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
    printf("The required transpose matrix will be :\n");
    for (int j = 0; j < c; j++)
    {
        for (int i = 0; i < r; i++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}