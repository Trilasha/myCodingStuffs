//***Code for Q10***
#include <stdio.h>
#include <string.h>
int main()
{
    char str[30];
    printf("Enter a string:\n");
    gets(str);
    printf("The first non-repeating character in the string(%s) is : ",str);
    int count=0;
    for (int i = 0; i < strlen(str); ++i)
    {
        count=0;
        for (int j = i+1; j <strlen(str); ++j)
        {
           if(str[i]==str[j])
           count++;

        }
        if(count==0)
        {
        printf("%c",str[i]);
        goto end;
        }
    }
    end:
    printf("\n");
    return 0;
}