//***Code for Q2***
#include <stdio.h>
#include <string.h>
int main()
{
    char str[50];
    printf("Enter a string to check whether it is a palindrome or not:\n");
    gets(str);
    char str_copy[50];
    strcpy(str_copy, str);
    strrev(str);
    if (strcmp(str_copy, str) == 0)
        printf("YES!The given string is a palindrome");
    else
        printf("NO!The given string is not a palindrome");

    return 0;
}