//Example of recursive case


#include <stdio.h>
int factorial(int number)
{
    if (number == 1 || number == 0) //Do format document using rightclick to avoid any problem regarding spacing
    {
        return 1;
    }
    else
    {
        return (number * factorial(number - 1));
    }
}

int main()
{
    int num;
    printf("Enter the number you want the factorial of\n");
    scanf("%d", &num);
    printf("The factorial of %d is %d\n", num, factorial(num));

    return 0;       //But what is the other way of solving this using iterative approach
}

