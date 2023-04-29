//To understand the use of extern(using two files,i.e,Ctut49copy.c and Ctut49b.c)


#include <stdio.h>
#include "Ctut49b.c"


//If two main functions are present then it will show an error
   extern int sum;  

int main()
{
//int sum =98;         //But if I take this line outside the main function
                           //then it will show an error because then there will be two global sum variables
                           //So confusion will arise between 98 and 988 
                           //Previously when this line was inside main function it returned the value assigned to the local one
                           //So if we want 988 value then write extern int sum;
                           //this will simply display the value as given in the Ctut49b.c file
                           //But again if both linenos.6 and 17 are written the 98 will be displayed due to local over global

 
    printf("The sum  is %d\n", sum);
    return 0;
}
