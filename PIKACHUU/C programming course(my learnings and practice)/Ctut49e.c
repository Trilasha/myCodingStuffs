#include <stdio.h>

    //Some examples to understand the concept of extern storage class ina  better way

//    int var;
//int main(void)
//{
//var = 10;
//return 0;
//}

//extern int var;
//int main(void)
//{
//return 0;
//}

//extern int var; //will show an error  because var has not been defined anywhere,so no memory allocation and without that we are trying to change its value to 10
//int main(void)
//{
//var = 10;
//return 0;
//}


//#include "somefile.h" //Assuming that this is a file which contains the  definition of var
//extern int var;
//int main(void)
//{
//var = 10;
//return 0;
//}



//A special case
/*
Do you think this program will work? Well, here comes another surprise from C standards. They say that..if a variable is only declared and an initializer is also provided with that declaration, then the memory for that variable will be allocated–in other words, that variable will be considered as defined. Therefore, as per the C standard, this program will compile successfully and work.
So that was a preliminary look at the extern keyword in C.
In short, we can say: 

A declaration can be done any number of times but definition only once.
the extern keyword is used to extend the visibility of variables/functions.
Since functions are visible throughout the program by default, the use of extern is not needed in function declarations or definitions. Its use is implicit.
When extern is used with a variable, it’s only declared, not defined.
As an exception, when an extern variable is declared with initialization, it is taken as the definition of the variable as well.
*/
//extern int var = 0;
//int main(void)
//{
//var = 10;
//printf("%d",var);
//return 0;
//}


int main()
{   

//*******   3 VERY IMPORTANT CONCLUSIONS    *******   
//register int x;
//int x=12;       //writing both these lines together will display errors since no definition and so no memory allocation(NOT ACCEPTED FORMAT)


//register int x;  //only the declaration
//x=14;            //then initialize and can be further changed          (ACCEPTED FORMAT)

register int x=12;  //definition(containing both declaration + initialization so memory allocation)

printf("%d",x);
int *ptr=&x;
printf("%d",ptr);
//An important and interesting point to be noted here is that we cannot obtain the address of a register variable using pointers.

return 0;
}




