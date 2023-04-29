#include <stdio.h>
int main()
{
    int s=0;
    while(s++<10)
    {
    if ((s<6)&&(s<7))
   continue;
   printf("%d\n",s);
    
    }
    return 0;
}