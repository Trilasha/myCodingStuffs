#include <stdio.h>
#include <string.h>
void rev_func(char *str)//if char *str[] is written then wrong output why???
{
    if(*str)//this line is the same as *str!='\0'
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
    puts(str);//automatically goes to a new line after printing
    printf("The reversed string(obtained using recursion):\n");
    rev_func(str);//when &str is written a peculiar warning appears but output is also correct
    return 0;
}


