//***Code for Q1***
#include <stdio.h>
int main()
{
    const int a=10;
    printf("The original value of a is : %d\n",a);
    int *ptr=&a;
    *ptr=12;
    printf("The new value of a(after changing it using pointers) is: %d",a);
    return 0;
}

