#include <stdio.h>
#include <stdlib.h>
int sum(int a, int b)
{
    return a + b;
}
void greetHelloAndExecute(int (*fptr)(int, int))
{
    printf("Hello World\n");
    printf("The sum of a and b is %d\n", fptr(5, 7));
}

void greetGmAndExecute(int (*fptr)(int, int))
{
    printf("Good Morning\n");
    printf("The sum of a and b is %d\n", fptr(5, 7));
}
int main()
{
    int (*ptr)(int,int);//Parentheses are very important in case of function pointers
    ptr=&sum; //Even without & it will work because function pointer points to an instruction which is already an address
greetGmAndExecute(ptr); //So the address of the sum function is passed to a function pointer in lineno.7
                              //So we are actually passing 'sum' function to 'void' function
    return 0;
}