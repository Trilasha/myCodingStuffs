#include <stdio.h>
int fun(char *p)
{
    char *q=p;
    while (*++p)
    ;
    return (p-q);
    
}
int main()
{
    char p[30];
    gets(p);
    int c=fun(p);
    printf("%d",c);

    return 0;
}