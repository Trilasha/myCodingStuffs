//Mine own one(luckily logic matched with the second one)but not giving accurate result
//showing all strings as palindromic sequence
//Where is the problem???
#include <stdio.h>
#include <string.h>
int palindrome(char str[])
{
int i=0;
while (i!=strlen(str))
{
if (str[i]=str[strlen(str)-i-1])
{
  return 1;
}
else
{
    return 0;
}

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