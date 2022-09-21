/*
Quick quiz
Given two numbers a and b,add them,subtract them and assign them to a and b using call by reference
a=4
b=3
output
a=7
b=1
*/

#include <stdio.h>
void func(int *x, int *y)
{
    *x = *x + *y;
    *y = *x-*y-*y;
    return;
}

int main()
{
    int a = 4, b = 3;
    printf("The original values of a and b are %d and %d respectively\n", a, b);
    func(&a, &b);
    printf("The values of a and b now are %d and %d respectively\n", a, b);

    return 0;
}