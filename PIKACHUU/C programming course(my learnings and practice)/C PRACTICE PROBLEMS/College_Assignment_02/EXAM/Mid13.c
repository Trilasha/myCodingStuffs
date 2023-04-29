#include <stdio.h>
int main()
{
    int a;
    printf("Enter a number");
    scanf("%d", &a);
    int sum1=0,sum2=0;
    while (a)
    {
       int s1;
       s1=a%10;
       sum1 +=s1;
       a=a/10;
       int s2;
       s2=a%10;
       sum2 +=s2;
       a=a/10;
    }
    if (sum1==sum2)
    {
        printf("EQUAL");
    }
    else if (sum1>sum2)
    {
     printf("Sum of odd places GREATER than even places");
    }
    else
    printf("Sum of odd places SMALLER than even places");
    return 0;
}