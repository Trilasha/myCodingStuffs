//*******Code for Q6*******
#include <stdio.h>
int main()
{  /* Increment/Decrement Operators are of 2 types:
               --1>PREFIX Increment/Decrement Operator
               --2>POSTFIX Increment/Decrement Operator */
    int a;
    printf("Enter an integer value:\n");
    scanf("%d", &a);
    printf("Intial entered value of a is : %d\n\n", a);
    printf("*******Understanding PREFIX Increment/Decrement operators*******\n");
    //Now pre-incrementing the current value of a by 1(PREFIX INCREMENT OPERATOR)
    printf("The value of a after incrementing by 1 is : %d\n", ++a);
    //Now pre-decrementing the new value of a by 1(PEFIX DECREMENT OPERATOR)
    printf("The new value of a after decrementing the previously incremented value by 1 is : %d\n\n", --a);

    printf("\\So the new obtained value of 'a' exactly matches with its originally entered value\\\n\n");

    printf("*******Understanding POSTFIX Increment/Decrement operators*******\n");
    int b, x1, x2, y1, y2;
    printf("Now again starting with the initial value of a as 9\n");
    printf("Enter another integer value:\n");
    scanf("%d", &b);
    printf("***So let us try to understand POST-INCREMENTATION by performing a simple addition\n");
    x1 = a++, y1 = b++;
    printf("The value of a after post increment is : %d\n", x1);
    printf("The value of b after post increment is : %d\n", y1);
    printf("But now the sum of a and b will be : %d\n\n", a + b);
    printf("Now the values of a and b are %d and %d respectively...\n", a, b);

    printf("***So let us try to understand POST-DECREMENTATION by performing another simple addition\n");
    x2 = a--, y2 = b--;
    printf("The value of a after post decrement is : %d\n", x2);
    printf("The value of b after post decrement is : %d\n", y2);
    printf("But now the sum of a and b will be : %d", a + b);

    return 0;
}