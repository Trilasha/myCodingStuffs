#include <stdio.h>
#define PI 3.14
int main()
{

    int a=6;
    // first way to use constant in the program 
    const float b=7.333;
   // b=7.22; cannot do this since b is a constant

    printf("The value of a is %d and the value of b is %0.5f\n",a,b);
    

    //another way to use a constant
   // PI= 3.14000; //on giving this we get an error since pi value is already defined
    printf("%f\n", PI);


// %a.bf plays a very important role in giving spaces between words



    //example to understand escape sequences
    printf("my tab character \t\t\t\t \a \? my backslash is \\n %10.7f", PI);

    return 0;
}
