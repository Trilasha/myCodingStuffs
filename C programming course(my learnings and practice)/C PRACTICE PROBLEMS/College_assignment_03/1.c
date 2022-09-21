//***Code for Q1***
#include <stdio.h>
int main()
{
    int num, original_num, reversed = 0;
    printf("Enter a number\n");
    scanf("%d", &num);
    original_num = num;
    // Checking palindrome or not starts from here
    while (num)
    {
        reversed = reversed * 10 + num % 10;
        num = num / 10;
    }
    if (original_num == reversed)
    {
        printf("YES! %d is a palindrome.", original_num);
    }
    else
        printf("NO! %d is not a palindrome.", original_num);
    return 0;
}