//***Code for Q6***
#include <stdio.h>
int main()
{
    int x, y, z, exp;
    printf("Enter a value for x:\n");
    scanf("%d", &x);
    printf("Enter a value for y:\n");
    scanf("%d", &y);
    printf("Enter a value for z:\n");
    scanf("%d", &z);
    printf("The values(entered by the user)are as follows:\n");
    printf("x=%d\ty=%d\tz=%d\n", x, y, z);
    exp = x++ + ++x + ++y + y++ + ++z;
    printf("The value of the expression--> x++ + ++x + ++y + y++ + ++z is %d\n", exp);
    printf("The updated value of x is %d\n", x);
    printf("The updated value of x is %d\n", y);
    printf("The updated value of x is %d", z);

    return 0;
}