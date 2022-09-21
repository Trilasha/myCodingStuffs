//Q6
#include <stdio.h>
int main()
{
    int a=-10,b=20;
    if(a>0 && b<0)
    a++;
    else if(a<0 && b<0)
    a--;
    else if(a<0 && b>0)
    b--;
    else
    b--;
    printf("%d\n",a+b);
    return 0;
}