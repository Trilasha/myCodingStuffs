#include <stdio.h>
int main()
{
    //using conditional operator
    //int x;
    //scanf("%d",&x);
    //int y=x<0?1:(x==0?0:-1);
    //printf("%d",y);

    //using nested if
    int x;
    scanf("%d",&x);
    if(x<0)
    printf("1");
    if(x==0)
    printf("0");
    if(x>0)
    printf("-1");
    return 0;
}