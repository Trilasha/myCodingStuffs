#include <stdio.h>
int main()
{
//  int  count=0,num=435;
//  while (num)
//  {
//     count++;
//     num>>=1;//
//  }
//  printf("count %d",count);
int a=6,b=30,c=10;
c+=(a>0 && --a>=5)?b/a:a--;
printf("%d %d",c,a);
    return 0;
}