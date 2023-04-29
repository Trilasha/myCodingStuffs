//To find the length of a string using pointers
#include <stdio.h>
int str_length(char *p)//p=&str1[0]
{
    int count1=0;//this initialization as 0 is important otherwise garbage value
    while (*p!='\0')
    {
       
       count1++;
       p++;

    }
    return count1;
}
int main()
{
    char str[100];
    printf("Enter the string\n");
    scanf("%s", str);
    int i=0;
    int count=0;
    while (str[i]!='\0')
    {
        i++;
        count++;
    }
    printf("The length of the string %s  is %d",str, count);
   

    //Using pointers now
char str1[100];
    printf("Enter the string\n");
    //scanf("%s", str1);
    scanf("%s", str1);
    int length=str_length(str1);
    printf("The length of the string %s is %d",str1,length);
    return 0;
}