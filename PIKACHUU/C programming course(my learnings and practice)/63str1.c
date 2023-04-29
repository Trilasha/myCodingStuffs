//Showing only error
#include <stdio.h>
#include <string.h>

int palindrome(char str[])
{
    if (strcmp(str, strrev(str)) == 0)
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