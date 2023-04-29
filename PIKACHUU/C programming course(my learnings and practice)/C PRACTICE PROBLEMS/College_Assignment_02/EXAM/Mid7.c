#include <stdio.h>
int main()
{
    int x,a,b,c;
a=40,b=60,c=60;
x=a>b?a:b>c?b:c;
printf("x=%d",x);
if (a>b)
{
    printf("x=%d",a);
}
else if (b>c)
{
   printf("x=%d",b);
}
else
{
    printf("x=%d",c);
}



    return 0;
}