//***Code for Q8***
#include <stdio.h>
int func()
{
    extern int sum;
    return sum;
}
int sum = 34;
int main()
{
    printf("The sum is : %d", func());
    return 0;
}