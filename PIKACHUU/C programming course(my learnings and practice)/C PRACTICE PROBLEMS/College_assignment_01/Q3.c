//*******Code for Q3*******
#include <stdio.h>
int main()
{
    float num1, num2;
    float product, quotient;
    printf("Enter the first floating-point number\n");
    scanf("%f", &num1);
    printf("Enter the second floating-point number\n");
    scanf("%f", &num2);
    product = num1 * num2;
    quotient = num1 / num2;
    printf("The product of the two floating-point numbers--> %0.1f X %0.1f = %f\n", num1, num2, product);
    printf("The quotient of the two floating-point numbers--> %0.1f / %0.1f = %f\n", num1, num2, quotient);

    return 0;
}