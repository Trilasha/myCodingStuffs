//***Code for Q8***
#include <stdio.h>
int main()
{
    printf("Enter the 1st 3 X 3 matrix:\n");
    int arr1[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &arr1[i][j]);
        }
    }
    printf("Enter the 2nd 3 X 3 matrix:\n");
    int arr2[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &arr2[i][j]);
        }
    }

    printf("The 1st matrix is : \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", arr1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("The 2nd matrix is : \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", arr2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    int(*ptr1)[3][3] = &arr1;
    int(*ptr2)[3][3] = &arr2;
    int sum;
    int arrx[3][3];
    int(*ptrx)[3][3] = &arrx;
    for (int i = 0; i < 3; i++)
    {
        sum = 0;
        for (int k = 0; k < 3; k++)
        {
            sum = 0;
            for (int j = 0; j < 3; j++)
            {

                sum += *(*(*ptr1 + i) + j) * (*(*(*ptr2 + j) + k));
            }
            *(*(arrx + i) + k) = sum;
        }
    }
    printf("The matrix obtained after multiplying 1ST MATRIX with 2ND MATRIX is:\n");
    for (int n = 0; n < 3; n++)
    {
        for (int g = 0; g < 3; g++)
        {
            printf("%d ", *(*(arrx + n) + g));
        }
        printf("\n");
    }
    return 0;
}