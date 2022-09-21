//Two programs are written in the notebook besides this...

#include <stdio.h>

int func1(int b)
{
    printf("The address of b inside func1 is %d\n", &b);
    return b*10;
}


int main()
{
    int b = 345;
    int val= func1(b);
    int *ptr=&val;
    printf("The value of func1 is %d\n", val);
    printf("The address of b inside main is %d\n", &b);    //Both the addresses are different as expected since both the b variables are different i.e,they are copies

    return 0;
}