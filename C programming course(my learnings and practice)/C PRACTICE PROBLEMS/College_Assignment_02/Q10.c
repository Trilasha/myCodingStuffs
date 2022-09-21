//***Code for Q10***
#include <stdio.h>
int main()
{
    int num1, num2, choice;
    printf("Enter the 1st number:\n");
    scanf("%d", &num1);
    printf("Enter the 2nd number:\n");
    scanf("%d", &num2);
    printf("Choose the arithmetic operation that you want to perform by pressing:\n");
    printf("1 for addition, \t2 for subtraction,\t3 for multiplication,\t4 for division\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("You have chosen ADDITION opration\n");
        printf("The sum-->%d + %d = %d", num1, num2, num1 + num2);
        break;
    case 2:
        printf("You have chosen SUBTRACTION opration\n");
        printf("The difference-->%d - %d = %d", num1, num2, num1 - num2);
        break;
    case 3:
        printf("You have chosen MULTIPLICATION opration\n");
        printf("The product-->%d X %d = %d", num1, num2, num1 * num2);
        break;
    case 4:
        printf("You have chosen DIVISION opration\n");
        printf("The quotient-->%d / %d = %d", num1, num2, num1 / num2);
        break;

    default:
        break;
    }
    return 0;
}