//To write a C program to compare two strings without using library function 
#include <stdio.h>
int main()
{
    char str1[10],str2[10];
printf("Enter the first string\n");
scanf("%s", str1);//gets(str1);
printf("Enter the second string\n");
scanf("%s", str2);
int i=0;
while (str1[i]==str2[i] && str1[i]!='\0')
{
   i++;

   }
if (str1[i]>str2[i])
{
    printf("str1>str2\n");
}
else if (str1[i]<str2[i])
{
    printf("str1<str2");
}
else
printf("str1=str2");

    return 0;
}