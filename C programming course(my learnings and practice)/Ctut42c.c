//Code to explain the usage of static variable

/*int ret()
{
    return 43*3;
}
*/
//And if we replace 1 in myvar with ret(); then it will show an error(refer to pointno.5)


#include <stdio.h>
int b = 34;
int func1(int b1)
{
    static int myvar = 1;              //If nothing defined then by default 0 is taken as the starting value
    printf("The value of myvar is %d\n", myvar);
    myvar++;
    return b1 + myvar;
}

int main()
{
    int b = 345;
    int val=func1(b);
    int *ptr=&val;
    printf("The value of the func1 is %d\n", val);

     val=func1(b);                                             //Called for the second time now
    printf("The value of the func1 is %d\n", val);
    return 0;
}