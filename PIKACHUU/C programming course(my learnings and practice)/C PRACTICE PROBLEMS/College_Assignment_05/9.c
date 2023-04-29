//***Code for Q9***
#include <stdio.h>
int main()
{
    int r1,c1,r2,c2;
   printf("For the 1st matrix-->Enter the number of rows and columns repectively:\n");
   scanf("%d %d",&r1,&c1);
   int arr1[r1][c1];
   printf("Enter the elements of the 1st matrix:\n");
   for (int i = 0; i < r1; i++)
   {
       for (int j = 0; j < c1; j++)
       {
           scanf("%d",&arr1[i][j]);
       }
   }
    printf("For the 2nd matrix-->Enter the number of rows and columns repectively:\n");
   scanf("%d %d",&r2,&c2);
   int arr2[r2][c2];
   printf("Enter the elements of the 1st matrix:\n");
   for (int i = 0; i < r2; i++)
   {
       for (int j = 0; j < c2; j++)
       {
           scanf("%d",&arr2[i][j]);
       }
   }
   printf("The 1st matrix is : \n");
    for (int i = 0; i < r1; i++)
   {
       for (int j = 0; j < c1; j++)
       {
           printf("%d ",arr1[i][j]);
       }
       printf("\n");
   }
   printf("\n");
   printf("The 2nd matrix is : \n");
    for (int i = 0; i < r2; i++)
   {
       for (int j = 0; j < c2; j++)
       {
           printf("%d ",arr2[i][j]);
       }
       printf("\n");
   }
   printf("\n");
   if (c1!=r2)
   {  printf("Sorry ...matrix multiplication is not possible since number of columns of the 1st matrix \nis not equal to the number of rows of the 2nd matrix.");
   }
   else
   { int sum;
   int arrx[r1][c2];
   for (int i = 0; i < r1; i++)
   {
       sum=0;
       for (int k = 0; k < c2; k++)
       {
           sum=0;
      for (int j = 0; j < r2; j++)
      {
         
         sum+=(arr1[i][j]*arr2[j][k]);
      }
      arrx[i][k]=sum;
       }}
   printf("The matrix obtained after multiplying 1ST MATRIX with 2ND MATRIX is:\n");
   for (int n = 0; n < r1;n++)
   {
      for (int g = 0; g < c2; g++)
      {
          printf("%d ",arrx[n][g]);
      }
      printf("\n"); }}   
       return 0;}