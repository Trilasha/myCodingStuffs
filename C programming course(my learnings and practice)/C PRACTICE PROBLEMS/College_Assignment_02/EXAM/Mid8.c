#include <stdio.h>
#include <math.h>
int main()
{
    int a,b,c;
printf("Value of a \n");
scanf("%d", &a);
printf("Value of b \n");
scanf("%d", &b);

printf("Value of c \n");
scanf("%d", &c);

if (a+b>c && b+c>a && a+c>b)
{
   printf("It can form a triangle.\n");
   int s=(a+b+c)/2;
int area =sqrt(s*(s-a)*(s-b)*(s-c));
printf("The area of the triangle formed is %d", area);
}
else
{
    printf("It cannot form a triangle.");
}

    return 0;
}