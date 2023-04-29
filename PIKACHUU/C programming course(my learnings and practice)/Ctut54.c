#include <stdio.h>
#include <stdlib.h>
int functionDangling()
{
    int a=34;
    int b=364;
    int sum=a+b;
    return &sum;//sum of scope is local which will get deleted once function returns
}



int main()
{
    //case1: De-allocation of a memory block

    int *ptr=(int *)malloc(7*sizeof(int));
    ptr[0]=34;
    ptr[1]=36;
    ptr[2]=64;
    ptr[3]=54;
    free(ptr); //ptr is now a dangling pointer

    //case2: Function returning local variable address
    int *dangPtr=functionDangling();  //dangPtr is now a dangling pointer

     int *danglingPtr3;
    //case3:If a variable goes out of scope
    {
int a =34;

    danglingPtr3= &a;
    }

//Here variable a goes out of scope which means danglingPtr3 is pointing to a location which is freed and hence
//danglingPtr3 is now a dangling pointer
    return 0;
}