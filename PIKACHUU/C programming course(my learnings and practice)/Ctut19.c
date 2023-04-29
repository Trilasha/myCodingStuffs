#include <stdio.h>




 // EXAMPLE FOR THE TYPE4 FUNCTION CODE(WITH RETURN AND ARGUMENTS)




/*int sum(int a, int b)     
{
    return a+b;
}
int main()
{
   int a,b,c;
   a=9;
   b=87;
   c=sum(a,b);
   printf("This sum is %d\n", c);
    return 0;
}*/



/*int main()                    //this code will show an error because function has been called first and it has been declared later...
{
   int a,b,c;
   a=9;
   b=87;
   c=sum(a,b);
   printf("This sum is %d\n", c);
    return 0;
}
    int sum(int a, int b)
{
    return a+b;

}*/




/*int sum(int a,int b);        //this is the declaration         //this code will give the desired result
int main()
{
   int a,b,c;
   a=9;
   b=87;
   c=sum(a,b);                //this is where we have called the function
   printf("This sum is %d\n", c);
    return 0;
}
    int sum(int a, int b)                  //this is where we have defined the function
{
    return a + b;
}
*/




// EXAMPLE FOR THE TYPE3 FUNCTION CODE(WITHOUT RETURN BUT WITH ARGUMENTS)





/*void printstar(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c", '*');       //because * is a character and single quote must be used(""= string and ''=character)
    }
}
int main()
{
   printstar (7);
    return 0;
}
*/



//EXAMPLE FOR THE TYPE2 FUNCTION CODE(WITH RETURN BUT WITHOUT ARGUMENTS)






/*int takenumber()
    {
        int i;
        printf("Enter a number\n");
        scanf("%d", &i);
        return i;
    }
int main()   //No parameters have been involved in the input

{
    int c;
    c=takenumber();
    printf("The number entered is %d\n", c);
     return 0;
}
*/





//EXAMPLE FOR TYPE1 FUNCTION CODE(WITHOUT RETURN AND WITHOUT ARGUMENTS) 
//DONE BY MYSELF SO NOT 100% SURE





void printstar(int n)
{
for (int i = 0; i < n; i++)
{
   printf("%c\n", '*');
}
}
int main()
{
    int n;
    printf("Enter the number\n");
    scanf("%d", &n);
    printstar(n);
    return 0;



}


