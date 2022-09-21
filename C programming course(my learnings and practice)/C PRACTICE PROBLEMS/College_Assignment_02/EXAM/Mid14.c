#include <stdio.h>
#include <string.h>
int count_char(char *str)
{
int cas[128]={0};
int i,c=0;
for (int i = 0; i < strlen(str); i++)
{
   cas[str[i]]=1;
}
for ( i = 0; i < 128; i++)
{
   c+=cas[i];
}
return c;
}
int main()
{
    char str[100];
printf("Enter a string\n");
gets(str);
printf("The numner of unique characters is %d", count_char(str));

    
    return 0;
}