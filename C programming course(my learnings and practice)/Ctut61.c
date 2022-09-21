//Solution to matrix multiplication(Exercise10)given in Ctut57.c
#include <stdio.h>
int main()
{
    int m, n, sum = 0;
    int a[3][4], b[4][2], result[3][2];
    printf("Enter your first matrix\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            //printf("Enter the %d %d element of your first matrix\n", i, j); //To make it look nice we are making these changes
            scanf("%d", &a[i][j]);
            //printf("\t");
        }
        //printf("\n");
    }

    printf("Enter your second matrix\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            //printf("Enter the %d %d element of your first matrix\n", i, j);
            scanf("%d", &b[i][j]);
           // printf("\t");
        }
       // printf("\n");
    }



for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
           //Calculate the elements of the new resultant matrix
           for (int k = 0; k < 4; k++)
           {
               sum +=a[i][k]*b[k][j];
           }
           result[i][j]=sum;
           sum=0;
        }
    }


//Print the resultant matrix
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 2; j++)
    {
        printf("%d\t", result[i][j]);
    }
    printf("\n");
}




    return 0;
}
//ONE DOUBT REMAINS REGARDING THE SPACE KEY!!!