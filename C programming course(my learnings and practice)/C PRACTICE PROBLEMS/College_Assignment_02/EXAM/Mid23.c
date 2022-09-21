#include <stdio.h>
int main()
{
    int n=0,max=0,second=0;
    int value,i=1;
    scanf("%d",&n);
while (i<n)
{
    scanf("%d",&value);
    if (value%2==0 && value>max)
    {
       second=max;
       max=value;
    }
    i++;
}
    printf("The second largest even number-->%d",second);
    return 0;
}