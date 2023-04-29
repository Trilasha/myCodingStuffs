//in this tutorial we have learnt creating user snippet(main2 is the name)
#include <stdio.h>
int main()
{
    int a =34;                //if instead of int we write char in both that adding 1 will add 1 sizeof(char) which has the value as 1
    int *ptra = &a;           //like char a= '3';char *ptra=&a;
    printf("%d\n", ptra);
    printf("%d\n", ptra+1);   //the arithmetic that ptr follows as per that adding 1 means adding 1 size of integer which has the value as 4(as per my architecture)
     printf("%d\n\v\v\v", ptra+2);  //similar for subtraction 
   
//To understand ptra++
   printf("%d\n", ptra);
   ptra++;        //ptra-- will also work in a similar way
   printf("%d\n", ptra);
   printf("%d\n", ptra+3);

   
    return 0;                 //while doing the same with deferencing,care must be taken that it has got a valid value otherwise it will show an error
}
                              //%d %p %c anything can be used but with %d it is easy to manipulate