//When the two values are already given in the code
#include <stdio.h>
#include <stdlib.h>

int average(int a,int b)
{
    return (a+b)/2;

}
void greetGaAndExecute(int (*fptr)(int, int))
{
    printf("Good Afternoon\n");
    printf("The average of a and b is %d\n", fptr(5, 7));
}
void greetGeAndExecute(int (*fptr)(int, int))
{
    printf("Good Afternoon\n");
    printf("The average of a and b is %d\n", fptr(5, 7));
}

int main()
{
    int (*ptr)(int,int);
    ptr=&average;
    //greetGaAndExecute(ptr);
greetGeAndExecute(ptr); //or else we can skip lineno.s 23 and 24 and write lineno.26 as greetGeAndExecute(average);
    return 0;
}