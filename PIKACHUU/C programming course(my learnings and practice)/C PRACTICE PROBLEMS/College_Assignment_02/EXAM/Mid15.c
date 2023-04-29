#include <stdio.h>
int main()
{
    int a=3;
    int b=++a + ++a;
    int c=a++ + a++;
    printf("A=%d\tB=%d\tC=%d\n",a,b,c);;
    return 0;
}