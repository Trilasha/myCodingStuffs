//*******Code for Q2*******
#include <stdio.h>
int main()
{
    int num1, num2;
    int add, sub;
    printf("Enter the first integer\n");
    scanf("%d", &num1);
    printf("Enter the second integer\n");
    scanf("%d", &num2);
    add = num1 + num2;
    sub = num1 - num2;
    printf("The sum of the two integers--> %d + %d = %d\n", num1, num2, add);
    printf("The difference of the two integers--> %d - %d = %d\n", num1, num2, sub);

    return 0;
}