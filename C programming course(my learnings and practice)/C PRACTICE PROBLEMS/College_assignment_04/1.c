//***Code for Q1***
#include <stdio.h>
void swap_by_value(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    printf("After swapping(USING CALL BY VALUE)-->\n");
    printf("The value of the first integer now : %d\n", a);
    printf("The value of the second integer now: %d\n", b);

    return;
}
int main()
{
    int num1, num2;
    printf("Enter the first integer:\n");
    scanf("%d", &num1);
    printf("Enter the second integer:\n");
    scanf("%d", &num2);
    printf("Before swapping-->\n");
    printf("The value of the first integer is  : %d\n", num1);
    printf("The value of the second integer is : %d\n", num2);
    printf("\n");
    swap_by_value(num1, num2);

    return 0;
}