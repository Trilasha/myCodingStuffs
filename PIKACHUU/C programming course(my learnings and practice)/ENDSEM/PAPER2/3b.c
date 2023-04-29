#include <stdio.h>
int f(int i)
{
    return i%2;
}
int main()
{
    int i=79;
    while (f(i))
    {
      printf("%4d",i);
      i=i/2;
    }
    return 0;
}