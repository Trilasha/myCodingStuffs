#include <stdio.h>
int func(int x)
{
    if (x<=0)
   return 1;
   return func(x-1)+2*(x-1);
    
}
int main()
{
    printf("%d",func(5));
    return 0;
}