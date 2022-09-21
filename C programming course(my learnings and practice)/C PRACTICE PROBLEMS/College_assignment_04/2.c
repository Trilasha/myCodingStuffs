//***Code for Q2***
#include <stdio.h>
int num1, num2;
void swap_by_reference(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int main()
{

    printf("Enter the first integer:\n");
    scanf("%d", &num1);
    printf("Enter the second integer:\n");
    scanf("%d", &num2);
    printf("BEFORE SWAPPING-->\n");
    printf("The value of the first integer is  : %d\n", num1);
    printf("The value of the second integer is : %d\n", num2);
    printf("\n");
    swap_by_reference(&num1, &num2);
    printf("AFTER SWAPPING (USING CALL BY REFERENCE)-->\n");
    printf("The value of the first integer now  : %d\n", num1);
    printf("The value of the second integer now : %d\n", num2);
    return 0;
}