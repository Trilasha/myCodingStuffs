#include <stdio.h>
int main()
{
    char x='a';
    printf("%d\n",x);
    char y;

    y='z'-1;
    printf("%c\n",y);
    printf("%d\n",y);

    int a,c;
    char g;
    a=5,g='a';
    c=a+g;
    printf("%d\n",c);

    return 0;
}