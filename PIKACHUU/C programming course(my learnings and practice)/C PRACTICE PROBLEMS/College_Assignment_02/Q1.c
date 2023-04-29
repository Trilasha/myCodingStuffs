//***Code for Q1***
#include <stdio.h>
int main()
{
    float num1, num2, tempVar;
    printf("Enter the first decimal number:\n");
    scanf("%f", &num1);
    printf("Enter the second decimal number:\n");
    scanf("%f", &num2);
    printf("Before swapping:\n");
    printf("The 1st number is : %.2f\n", num1);
    printf("The 2nd number is : %.2f\n", num2);
    tempVar = num1; //tempVar is the temporary variable created for swapping
    num1 = num2;
    num2 = tempVar;
    printf("After swapping:\n");
    printf("The 1st number becomes : %.2f\n", num1);
    printf("The 2nd number becomes : %.2f\n", num2);

    return 0;
}