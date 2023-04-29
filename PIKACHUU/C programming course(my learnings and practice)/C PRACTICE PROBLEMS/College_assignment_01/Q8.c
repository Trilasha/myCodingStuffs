//*******Code for Q8*******
#include <stdio.h>
int main()
{
    int num1, num2;
    printf("Enter the first number\n");
    scanf("%d", &num1);
    printf("Enter the second number\n");
    scanf("%d", &num2);
    for (int i = 1; i <= num2; i++)
    {
        num1++;
    }
    printf("The sum of the two entered numbers(without using '+') is %d", num1);

    return 0;
}