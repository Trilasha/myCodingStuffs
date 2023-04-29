#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Solution by Harry bhai
/*
_______EXERCISE TO MAKE A COMMAND LINE CALCULATOR FOR 2 NUMBERS________
You have to create a command line utility to add/subtract/divide/multiply two numbers
First command line argument of your C program must be the operation.
The next two arguments being the two numbers.For example;
>>Command.c add 45 4
>>49
*/
int abs(int n)
{
    if (n<0)
    {
        return(n*-1);
    }
    else{
        return(n);
    } 
    
}
int main(int argc,char *argv[])
{
    char *operation;
    int num1,num2;
    operation=argv[1];
    num1=atoi(argv[2]);  //Since num is int and argv is string,so atoi() is used which takes a string and returns an int
    num2=atoi(argv[3]);  //It is a function of stdlib.h
    printf("Operation %s\n", operation);
    printf("Num1 is %d\n", num1);
    printf("Num2 is %d\n", num2);

if (strcmp(operation,"add")==0)
{
    printf("%d\n", num1+num2);
}
else if (strcmp(operation,"subtract")==0)
{
   int n;
   n=num1-num2;
   printf("%d", abs(n)); //***This abs part is my own addition***
    
}
else if (strcmp(operation,"multiply")==0)
{
    printf("%d\n", num1*num2);
}
else if (strcmp(operation,"divide")==0)
{
    printf("%d\n", num1/num2);
}

    return 0;
}