//*******Code for Q7*******
#include <stdio.h>
int main()
{
    int x, y,a,b;
    //Let us perform an addition to understand the unary pre and post-incrementation
    printf("Enter the first integer value(say X):\n");
    scanf("%d", &x);
    printf("Enter the second integer value(say Y):\n");
    scanf("%d", &y);
    a=++x; //PRE-INCREMENTATION
    b=y++; //POST-INCREMENTATION
    printf("After the pre-incrementation of X and post-incrementation of Y,\n");
    printf("The sum of both comes out to be : %d", a+b);

    return 0;
}