#include <stdio.h>

void printstr(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        printf("%c", str[i]);
        i++;
    }
}

int main()
{
    char str[5] = {'h', 'a', 'r', 'r', 'y', '\0'}; //unless we put the null value it wil not be a valid string and will also show some garbage value
    //char str[]="harry";                          //this is the another way of writing the above line
    printstr(str);                                 //In this case,[]>=6 to get accuracy otherwise error garbage will appear
    return 0;
}