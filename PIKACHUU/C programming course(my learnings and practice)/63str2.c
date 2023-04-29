//running smoothly and giving accurate results(taken from the comment section)
#include <stdio.h>
#include <string.h>

int palindrome(char str[])  
{
    int a = 0;
    for (int i = 0; i < strlen(str) / 2; i++)
    {
        if (str[i] == str[strlen(str) - i - 1])//Problem arises with i and strlen if str[] is not written in the first line why???
        {
            a++;
        }
    }

    if (a == strlen(str) / 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    char str[34];
    printf("Enter the word to check whether it is a palindrome or not:\n");
    scanf("%s", &str);
    printf("The reversed string will be:");
    puts(strrev(str));
    printf("\n");
    if (palindrome(str))
    {
        printf("YES!It is a palindromic sequence...");
    }
    else
    {
        printf("NO!It is not a palindromic sequence...");
    }

    return 0;
}