//To understand the usage of global variables

#include <stdio.h>
int b= 34;//This is a global variable
int func1(int b1)
{
    printf("The value of b inside func1 is %d\n", b);//local will get priority over global
    return b1 *10;                                    //in case if b1 is written then no local no formal parameter so global will win
                                                     //if both b1 is agai replaced by b then 345 will be the result
}



int main()
{
    int b= 345;                                //b is a local variable of main function
    int var=func1(b);       
    int *ptr=&var;
    return 0;                                  
}                  
                                               // Suppose int loc = 45;is written inside func1(); and if we write 
                                               //printf("%d", loc); inside main function then it will show an error