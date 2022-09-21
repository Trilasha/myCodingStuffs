#include <stdio.h>
int sum=9;             //or simply by writing this here as a global variable will also work
int myfunc(int a, int b)
{
   // auto int sum;      //without auto will also mean the same
   // sum = a + b;
    return sum;
}

int main()
{
    //Declaration-Telling the compiler about the variable(No space reserved)
    //Definition-Declaration + Space reservation
    int sum = myfunc(3,5);
    printf("The sum  is %d\n", sum);

    return 0;
}





//CONCLUSIONS:
//On commenting out lineno.14,we get sum as 0
//On commenting out lineno.02,we get the sum as 8
//On commenting out linenos. 05 and 14,we get the sum as 0
//If we don't comment anything,the sum willbe 8 because local dominates over global

