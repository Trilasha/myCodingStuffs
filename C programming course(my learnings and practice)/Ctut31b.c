//another example to show call by reference

#include <stdio.h>
void changeValue(int* address)
{
    *address=345;
}

int main()
{
    int c = 34, d = 56;
    printf("The value of c now is %d\n", c);
    changeValue(&c);
    printf("The value of c now is %d\n", c);
    return 0;
}
//Examples for call by value are available in Ctut19.c