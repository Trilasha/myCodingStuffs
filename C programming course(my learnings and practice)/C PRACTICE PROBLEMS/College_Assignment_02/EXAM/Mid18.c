#include <stdio.h>
int main()
{
    int a,b;
    char ch;
    scanf("%d%c%d",&a,&ch,&b);
if (a<0 || ch!='+' || b<0)
{
   printf("Invalid Input");
}
else
{
    switch (ch)
    {
    case '+':
       printf("%d",(a+b));
        break;
    
    default:
        printf("Invalid Operati0n");
    }
}


    return 0;
}