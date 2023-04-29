#include <stdio.h>


int main()
{
    int a = 345;
    float b=8.3;
    void  *ptr;
    ptr=&a;
    ptr = &b;
    printf("The value of a is %f\n", *(float *)ptr);  //If only *ptr then error will be displayed
    ptr = &a;                                         //So now it is typecasted to become an integer/float pointer 
                                                      //which can be easily deferenced now
    printf("The value of a is %d\n", *(int *)ptr);


//Note when we did malloc and calloc,there also we typecasted the pointer because they return void pointer by default
    return 0;                                      
}