//***Code for Q4***
#include <stdio.h>
int power(int num, int p)
{
    if (p == 0)
    {
        return 1;
    }
    else
        return num * power(num, p - 1);
}
int main()
{
    int num;
    printf("Enter a number:\n");
    scanf("%d", &num);
    int p;
    printf("Enter the power of %d:\n", num);
    scanf("%d", &p);
    printf("The vale of %d to the power %d is :  %d\n", num, p, power(num, p));

    return 0;
}