#include <stdio.h>
int main()
{
    // typedef <previous_name> <alias_name>;
   // typedef unsigned Long ul;                                        //MY TYPEDEF UNSIGNED LONG IS NOT WORKING
    typedef int integer;
   // ul l1, l2, l3;
    integer a = 4;
    printf("The value of a is %d", a);
    return 0;
}