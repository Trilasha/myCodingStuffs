//Q4-->Not able to understand
#include <stdio.h>
int main()
{
    int i;
for ( i = 0; i < 20; i++)
{
switch (i)
{
case 0:i+=5;
case 1:i+=2;
case 2:i+=5;
default:i+=4;
}
printf("%d",i);
}
    
    return 0;
}