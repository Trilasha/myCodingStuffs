//***Code for Q10***
#include <stdio.h>
int main()
{
    // auto is the default storage class for all the variables declared inside a function or a block
    auto int a = 3; // auto int a=3 is the same as int a=3
    printf("a=%d\n", a);
    {
        auto int i = 10;
        printf("Since now we are printing the value of i inside its scope,so it will display the accurate value stored in the variable i,i,e,\n");
        printf("i=%d\n", i);
    }
    printf("But now we are outside the scope,so if we try to print the value stored in i,it wil show an error and the program will not get executed\n");

    // The code that will cause error is shown below(in the comments)
    /*printf("i=%d",i);*/

    return 0;
}