//***Code for Q1***
#include <stdio.h>
#include <string.h>
int main()
{
    char str1[20];
    printf("Enter the 1st string(str1):\n");
    gets(str1);
    printf("Enter the 2nd string(str2):\n");

    char str2[20];
    gets(str2);
    printf("\nBefore swapping:\n");
    printf("str1=%s\n", str1);
    printf("str2=%s\n\n", str2);
    char str3[20];
    strcpy(str3, str2);
    strcpy(str2, str1);
    strcpy(str1, str3);
    printf("After swapping:\n");
    printf("str1=%s\n", str1);
    printf("str2=%s\n", str2);
    return 0;
}