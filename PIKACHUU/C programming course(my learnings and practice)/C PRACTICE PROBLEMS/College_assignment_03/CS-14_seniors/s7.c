//Question7
#include <stdio.h>
int main()
{
int n;
scanf("%d",&n);
for (int i = 1; i < 6; i++)
{
    for (int j = 1; j<i+1; j++)
    {
      printf("%d",j);
    }
    printf("\n");
}
    return 0;
}