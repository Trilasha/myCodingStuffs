#include <stdio.h>
/*
Pint a multiplication table of a number entered by the user in pretty form

Example:

Input
Enter the number you want multiplication table of:
6

Output:
Table of 6:
6x1=6
6x2=12
6x3=18
6x4=24
6x5=30
6x6=36
6x7=42
6x8=48
6x9=54
6x10=60




*/
int main()
{
    int a;
    printf("Enter the number you want multiplication table of\n");
    scanf("%d", &a);
    printf("Table of the given number %d is\n", a);
    printf("ax1=%d\n", a*1);
    printf("ax2=%d\n", a*2);
    printf("ax3=%d\n", a*3);
    printf("ax4=%d\n", a*4);
    printf("ax5=%d\n", a*5);
    printf("ax6=%d\n", a*6);
    printf("ax7=%d\n", a*7);
    printf("ax8=%d\n", a*8);
    printf("ax9=%d\n", a*9);
    printf("ax10=%d\n", a*10);





//let's try to do this usind do while loop(learnt from video number 13)




int num, i=0;
printf("Enter the number\n");
scanf("%d", &num);
 printf("The multiplication table of %d is given below\n", num);

do
{
   i=i+num;
   printf("%d\n", i);
} while (i<=61);










    return 0;
}


//solution to this by HARRY SIR is given in Ctut20.c


