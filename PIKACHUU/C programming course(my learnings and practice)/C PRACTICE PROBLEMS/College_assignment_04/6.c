//***Code for Q6***
#include <stdio.h>
int prime(int i, int num)
{
    if (num == i)
    {
        return 0;
    }
    else if (num % i == 0)
    {
        return 1;
    }
    else
        return prime(i + 1, num);
}
int main()
{
    int num;
    printf("Enter a number to check whether it is prime or not:\n");
    scanf("%d", &num);
    if (num == 1)
    {
        printf("1 is neither prime nor composite\n");
    }
    else if (prime(2, num) == 0)
    {
        printf("It is a prime number\n");
    }
    else
        printf("It is not a prime number\n");

    return 0;
}