#include <stdio.h>
int main()
{
    //problem 10
    //My method but not the general one where n can be taken from the user
    //int i, j;
    //for (int i = 1; i <= 4; i++)
    //{
    //    for (int j = 1; j <= 7; j++)
    //    {
    //        if (j >=5-i && j<=3+i)
    //            printf("*");
    //        else
    //            printf(" ");
    //    }
    //    printf("\n");
    //}
    //for (int i = 1; i<=3; i++)
    //{
    //    for (int j = 1; j<=7; j++)
    //    {
    //        if (j>=1+i && j<=7-i)
    //        {
    //            printf("*");
    //        }
    //        else
    //        printf(" ");
    //    }
    //    printf("\n");
    //}


    //problem 10(mysirG.com)
    //not the generalized method
    //int i, j,k=0;
    //for (int i = 1; i <= 7; i++)
    //{
    //    i<=4?k++:k--;
    //    for (int j = 1; j <= 7; j++)
    //    {
    //        if (j>=5-k && j<=3+k)
    //            printf("*");
    //        else
    //            printf(" ");
    //    }    
    //        printf("\n");
    //}

    //problem 10(mysirG.com)
    //The generalized method(when n=odd)
    //however for n=even it will print the middle line 2 times if we want that then follow the code following this
    //int i, j,k=0,rows,n;
    //printf("Enter the number of rows that you want:\n");
    //scanf("%d",&rows);
    //n=(rows+1)/2;
    //for (int i = 1; i <= rows; i++)
    //{
    //    i<=n?k++:k--;
    //    for (int j = 1; j <= rows; j++)
    //    {
    //        if (j>=n+1-k && j<=n-1+k)
    //            printf("*");
    //        else
    //            printf(" ");
    //    }    
    //        printf("\n");
    //}


//problem 10(mysirg.com)
//The generalized method for both n=odd and even
int i, j,k=0,rows,n;
printf("Enter the number of rows that you want:\n");
scanf("%d",&rows);
n=(rows+1)/2;
for (int i = 1; i <= rows; i++)
{
    if (rows%2==0)
    {
        if(i<=n) k++;
        if(i>n+1) k--;
    }
    else
    i<=n?k++:k--;
    for (int j = 1; j <= rows; j++)
    {
        if (j>=n+1-k && j<=n-1+k)
            printf("*");
        else
            printf(" ");
    }    
        printf("\n");
}

    return 0;
}