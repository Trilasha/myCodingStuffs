//To print a matrix in spiral form
#include <stdio.h>
int main()
{
    //int arr[3][2]={{12,14},{3,4},{6,9}};
    //for (int i = 0; i < 3; i++)
    //{
    //    for (int j = 0; j < 2; j++)
    //    {
    //        printf("%d ",arr[i][j]);
    //    }
    //    printf("\n");
    //}
    int r, c;
    printf("Enter the number of rows\n");
    scanf("%d", &r);
    printf("Enter the number of columns\n");
    scanf("%d", &c);
    printf("Enter the elements of the matrix:\n");
    int arr[r][c];
    int i, j;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("The entered matrix is:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\nSpiral matrix:\n");
    int k=0,l=0;
    while (k<r && l<c)
    {
       for (i = l; i < c; i++)
       {
           printf("%d", arr[k][i]);
       }
       k++;
       for (i = k; i < r; i++)
       {
           printf("%d",arr[i][c-1]);
       
    }
    c--;
if (k<r)
{
   for (i=c-1; i >=0;--i)
   {
       printf("%d",arr[r-1][i]);
   }
   r--;
}
if (l<c)
{
    for ( i = r-1; i >= k; i--)
    {
       printf("%d", arr[i][l]);
    }
    l++;
}
}


    


    return 0;
}