//***Code for Q9***
#include <stdio.h>
int main()
{
    register int x;
    register int y = 100;
    // the variables x and y will be stored in the register of the microprocessor if free registers are available
    printf("Since x has not been initialized,so it will store a garbage value(initial value of a register value).\n ");
    printf("Hence the value of x = %d\n", x);
    printf("But the register variable y has been initialized so it will store that user fed value.\n");
    printf("Hence the value of y = %d", y);

    return 0;
}