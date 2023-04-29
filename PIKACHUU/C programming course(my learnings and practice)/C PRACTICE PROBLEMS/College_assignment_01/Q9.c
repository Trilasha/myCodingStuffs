//*******Code for Q9*******
#include <stdio.h>
int main()
{
    int num1, num2;
    int quotient, remainder;
    printf("Enter the first number:\n");
    scanf("%d", &num1);
    printf("Enter the second number:\n");
    scanf("%d", &num2);
    quotient = num1 / num2;
    remainder = num1 % num2;
    printf("The quotient of the two entered numbers is : %d\n", quotient);
    printf("The remainder of the two entered numbers is : %d", remainder);

    return 0;
}