#include <stdio.h>
int main()
{
    int a=5,b=120,c=10;
   c+=(a<0  || ++a>=5)?b/a:a--;
    printf("%d %d\n",c,a);
        c+=(a<0  && ++a>=5)?b/a:a--;
    printf("%d %d",c,a);

     
 
    return 0;
}