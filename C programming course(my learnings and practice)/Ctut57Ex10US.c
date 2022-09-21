//Matrix Multiplication Exercise10


#include <stdio.h>
int main()
{
int r,c;
int array1[r][c];
    printf("Enter the number of rows in the first array\n");
    scanf("%d", &r);
     printf("Enter the number of columns in the first array\n");
    scanf("%d", &c);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d\t", &array1[i][j]);
            printf("%d\t", array1[i][j]);

        }
        
        printf("\n");
    }
    




    return 0;
}

//Solution by Harry bhai is given in Ctut61.c