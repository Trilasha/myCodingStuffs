//***Code for Q8***
#include <stdio.h>
#include <string.h>
void rev_func(char *str)
{
    if(*str)
    {
  rev_func(str+1);
  printf("%c",*str);
    }
}
int main()
{
    char str[50];
    printf("Enter a string:\n");
    gets(str);
    printf("The entered string is :\n");
    puts(str);
    printf("The reversed string(obtained using recursion):\n");
    rev_func(str);
    return 0;
}


