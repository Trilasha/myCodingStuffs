//***Code for Q3***
#include <stdio.h>
long long int factorial(int num)
{
    if (num == 0 || num == 1)
        return 1;
    else
        return num * factorial(num - 1);
}
int main()
{
    int num;
    printf("Enter the number that you want factorial of:\n");
    scanf("%d", &num);
    printf("The factorial of %d is : %lld", num, factorial(num));

    return 0;
}