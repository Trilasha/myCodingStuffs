/*Example for the demonstration of CALL BY REFERENCE(Very important from exam point of view)*/

#include <stdio.h>   
void swap(int *x, int *y)      //function definition to swap the values
{
    int temp;
    temp = *x;                 //saves the value whose address is at x(or saves the value at addrress x)
               *x = *y;        //put y into x
               *y= temp;       //put temp into y
    return;
}
int main()                     //always start reading a C program from the main function part
{
   int a=34,b=74;
   printf("%d and %d\n",a ,b);//suppose if the address of a is A and b is B then x stores A and y stores B
   swap(&a,&b);
   printf("%d and %d\n", a,b);
   return 0;
}



