#include <stdio.h>
int main()
{
    int n;
scanf("%d",&n); 
int c=0; 
while(n)
 {
    n-=16;
    c++;
 }
 printf("%d",c);

    return 0;
}