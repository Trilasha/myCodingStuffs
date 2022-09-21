#include <stdio.h>
#include <stdlib.h>
int sum(int a,int b)
{
    return a+b;
}

int main()
{
    printf("The sum of 1 and 2 is %d\n", sum(1,2)); //Testing the function
    int (*fptr)(int,int);//Declaring a function pointer //Denotes a pointer that points to a function which takes two integers as input and returns an integer
    fptr=&sum;
    int d=(*fptr)(4,6);//This is the advantage of using function pointer(here fptr has been dereferenced)
    printf("The value of d is %d\n", d);
    
    return 0;
}