#include <stdio.h> //Vscode can be learnt from one video present with his python course

int main()
{
    printf("Let's learn about pointers\n");
    int a=76;
    int *ptra = &a;
    printf("The value of a is %d\n", *ptra);                 //*means deferencing the pointer                   //printf format specifier reference(googled)...so if %x and only ptra(without*)will return the hexadecimal value of address of the variable
    printf("The address of a is %x\n", ptra);                //ADDRESS OF A(THE VARIABLE)in hexadecimal form    //ptra is the pointer(which is also a variable)

    printf("The address of the pointer to a is %p\n", &ptra);//ADDRESS OF THE POINTER THAT STORES A 
    printf("The value of a is %p\n\v\v\v", *ptra);           //VALUE OF A

    //ptra=&a=address of a 
    //*ptra=a-value of a
    //&ptra=address of the pointer
    //%p %x %d %c are format specifiers and any one can be used for pointers as per our demand 
    //Their meanings can be searched from google for further understandings


    //In short the below two lines are same
    printf("The value of a is %d\n", a);                    //VALUE OF A 
    printf("The value of a is %d\n ", *ptra);                //VALUE OF A 

    //Example to show null pointer

    /* 
    int *ptr2;
    printf("The address of some garbage is %p\n", ptr2);
    */                                                       //will show some garbage value

    //But in order to return a null value,type this code
    int *ptr2= NULL;
    printf("The value of some garbage is %p\n", ptr2);


    



    
    return 0;
}
