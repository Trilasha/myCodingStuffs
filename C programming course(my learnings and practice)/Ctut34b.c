//Code that asks user to type the string values

#include <stdio.h>


void printstr(char str[])
{
    int i=0;
    while (str[i]!='\0')
    {
        printf("%c", str[i]);                        //Why %s doen't show any value???????????
        i++;
    }
    printf("\n");
}



int main()
{
    char str[3];                                     //Even if 3 is written but more than 3 characters are accepted and displayed how???
    gets(str);

    printf("Using custom function printstr\n");
    printstr(str);         //type 3                  //Why type 3 is applicable here and how???  

    printf("%s\n", str);   //type 1

    puts(str);             //type 2


    return 0;
}
