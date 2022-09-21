//***Code for Q3***
#include <stdio.h>
#include <string.h>
int main()
{
    
    char str[30];
    printf("Enter a string:\n");
    gets(str);
    printf("The entered string is:\n");
    puts(str);
    int count=1;
    int maximum=1;
    char ch;
    for (int i = 0; i < strlen(str); ++i)
    {
        count=1;
        for (int j = i+1; j < strlen(str); ++j)
        {
           if(str[i]==str[j])
           count++;
        }
        if(count>maximum)
        {
            ch=str[i];
        }
    }
    printf("The maximum occurring character in the input string is : %c",ch);
    return 0;
}