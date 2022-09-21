//To further understand the concept of extern(now within one file)
#include <stdio.h>
int myfunc(int a, int b)
{
    //auto int sum;                              //On commenting out only lineno.5,we get the sum as 9
     // extern int sum;                            //On commenting both linenos.5 and 7,we get the sum as 343
    //sum = a + b;                               //If all three linenos.5,6 and 7 are commented out then error will be displayed but the same will not be displayed if int sum=343;is written at the top
    return sum;                                  //If in extern is removed then int sum; will  become a local variable of myfunc and hence will return a garbage value
}

int sum = 343;        

int main()
{
    //int sum = myfunc(3, 6);
    printf("The sum is %d\n", sum);
    
    return 0;
}

//*******Comment out the body of the function in 49.c and 49copy.c and then observe thow the on changing the position
//of the global variable will affect the output and also analyse how extern removes the error when the
//the global variable is not at the top*******