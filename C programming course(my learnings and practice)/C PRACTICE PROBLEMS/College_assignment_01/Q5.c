//*******Code for Q5*******
#include <stdio.h>
int main()
{
    /*The common and basic arithmetic operations are:
    -->Addition
    -->Subtraction
    -->Multiplication
    -->Division
    */
    float num1, num2;
    printf("Enter the first number:\n");
    scanf("%f", &num1);
    printf("Enter the second number:\n");
    scanf("%f", &num2);
    printf("The sum of the two given numbers(%.1f + %.1f) is : %f\n", num1, num2, num1 + num2);
    printf("The difference of the two given numbers(%.1f - %.1f) is : %f\n", num1, num2, num1 - num2);
    printf("The product of the two given numbers(%.1f X %.1f) is : %f\n", num1, num2, num1 * num2);
    printf("The quotient of the two given numbers(%.1f / %.1f) is : %f\n", num1, num2, num1 / num2);
    return 0;
}