//To understand static storage class


#include <stdio.h>
int myfunc(int a,int b)
{
    static int myvar;
    //printf("The sum is %d\n", myvar); //With different posiions of printf,output will also change
    myvar++;
     printf("The sum is %d\n", myvar);
    return myvar;

}


int main()
{
    int myvar= myfunc(3,6);  //For register variable write register before int in this line(cannot be seen directly in the output) 
    myvar= myfunc(3,6);
    myvar= myfunc(3,6);      ////myfunc funtion has been called 4times 
    myvar= myfunc(3,6);      
    return 0;
}