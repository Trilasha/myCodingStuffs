#include <stdio.h>
#include <string.h>

int main()
{
    char s1[100],s2[100];
    printf("Enter the 1st string : \n");
    gets(s1);
    //s1 == s2;
    strcpy(s2,s1);
   // puts(strrev(s1));
   
    if(strcmp(s2,strrev(s1))==0){
        printf("The given string is a Palindrome ");
    }
    else {
        printf("The given string is not palidrome ");
    }
   // return 0;
}