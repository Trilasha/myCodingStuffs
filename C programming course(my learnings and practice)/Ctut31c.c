//Example showing Call by value taken from Ctut19.c

#include <stdio.h>
int takenumber()
    {
        int i;
        printf("Enter a number\n");
        scanf("%d", &i);
        return i;
    }
int main()   //No parameters have been involved in the input

{
    int c;                      //line nos.12 and 13 can also be written as int c;c=takenumber();
    int s=takenumber(c);
    printf("The number entered is %d\n", s);
     return 0;
}