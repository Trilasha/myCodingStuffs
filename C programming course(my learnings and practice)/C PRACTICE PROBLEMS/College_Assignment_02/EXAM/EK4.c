#include <stdio.h>
int main()
{
    int a[5],i,b=16;
for(i=0;i<5;i++)    
a[i]=2*i;
f(a,b);
for(i=0;i<5;i++)
printf("\n%d\n", a[i]);
printf("\n%d\n", b);
}

f(int x[],int y)
{
    int i;
    for(i=0;i<5;i++)
    x[i]+=2;
    y+=2; 
    //no change in the value of b because the function has ben called by value and not by reference 
    //so any change in th formal argument will not get reflected in the actual argument
    //very important concept+when no braces are present after if,for statements the only one one statement can be included within that
    
}