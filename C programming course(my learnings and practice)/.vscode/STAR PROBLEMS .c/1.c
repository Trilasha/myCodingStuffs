#include <stdio.h>
int main()
{
    /*
    -->The general layout
int i,j;
for (int i = 1; i <=3; i++)
{
 for (int j= 1;j<=5; j++)
 {
     printf("* ");
 }
 printf("\n");
}
*/

int i,j;
for (int i = 1; i <=5; i++)
{
 for (int j= 1;j<=5; j++)
 {
     if(j<=i)
     printf("* ");
     else
     printf(" ");
 }
 printf("\n");
}
    return 0;
}