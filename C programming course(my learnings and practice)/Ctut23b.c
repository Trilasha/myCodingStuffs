#include <stdio.h>

int main()
{
    int marks[2][4] = {{45, 235, 34, 198}, 
                       {6, 7, 8, 9}};

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
           // printf("The value of %d, %d element of the array is %d\n", i, j, marks[i][j]);
           printf("%d\t", marks[i][j]);
        }          
        printf("\n");
    }                                               //lines13 and 15 are written for matrix form otherwise only  lineno.12 will also work

    return 0;
}
