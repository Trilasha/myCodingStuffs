//***Code for Q7***
#include <stdio.h>
#include <string.h>
int main()
{
    char str1[30];
    char str2[30];
    printf("Enter the 1st string (say str1):\n");
    gets(str1);
    printf("Enter the 2nd string (say str2):\n");
    gets(str2);
    char str3[30];
    strcpy(str3, str1);
    strcat(str3, str1);
    char *sub;
    sub = strstr(str3, str2);
    if (sub)
        printf("YES! str1 and str2 are rotations of each other");
    else
        printf("NO! str1 and str2 are not rotations of each other");
    return 0;
}