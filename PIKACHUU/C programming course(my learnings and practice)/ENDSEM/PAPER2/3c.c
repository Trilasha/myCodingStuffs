#include <stdio.h>
int main()
{
    int a[7]={12,18,8,16,14,22,19};
    int *p1=&a[1];
    int *p2=p1+3;
    int *p3=p2+2;
    printf("%d ",*p2);
    printf("%ld ",p2-p1);
    printf("%d",a[p3-p1]);
    return 0;
}