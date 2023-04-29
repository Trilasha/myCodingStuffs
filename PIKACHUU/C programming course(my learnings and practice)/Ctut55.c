#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a = 334;
    int *ptr; //This is a wild pointer
    //*ptr = 34; //If code is written only till this line and then run then it is very risky hence should not be done
    ptr = &a; //ptr is no longer a wild pointer
    printf("The value of a is %d\n", *ptr);
    return 0;
}