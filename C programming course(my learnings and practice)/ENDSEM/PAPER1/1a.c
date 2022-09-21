#include <stdio.h>
void areSame(int a, int b)
{
    //way1
    //if (a ^ b)
    //    printf("Not same");
    //else
    //    printf("Same");

    //way2
    if ((a & ~b) == 0)
         printf("same");
    else
        printf("Not same");
}
int main()
{
    areSame(10, 20);
    return 0;
}