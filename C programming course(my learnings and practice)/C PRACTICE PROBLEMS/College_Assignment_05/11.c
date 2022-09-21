#include <stdio.h>
int main()
{
    int c;
    int *a=&c;
    c=-3;
    printf("%d\n",a);
    printf("%u\n",a);//both will give the same output
    printf("%d\n",*a);
    printf("%u\n",*a);


    return 0;
}