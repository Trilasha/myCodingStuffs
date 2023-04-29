//***Code for Q5***
#include <stdio.h>
double product(float num1, float num2)
{
    if (num2 == 1)
    {
        return num1;
    }
    else
        return num1 + product(num1, num2 - 1);
}
int main()
{
    float num1, num2;
    printf("Enter the first number:\n");
    scanf("%f", &num1);
    printf("Enter the second number:\n");
    scanf("%f", &num2);
    printf("The product of the given two numbers is : %.00Lf", product(num1, num2));
    return 0;
}