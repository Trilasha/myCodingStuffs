//***Code for Q2***
#include <stdio.h>
int main()
{
    int n, i, j, k;
    printf("Enter a number :");
    scanf("%d", &n);
    printf("All the prime numbers between 1 and %d are as follows:\n",n);
    for (i = 1; i <= n; i++)
    {
        k = 0;
        for (j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                k++;
                break;
            }
        }
        if (k == 0 && i != 1)
        {
            printf(" %d", i);
        }
    }

    return 0;
}

//-->
/*
The init step is executed first, and only once. This step allows you to declare and initialize any loop control variables. You are not required to put a statement here, as long as a semicolon appears.

Next, the condition is evaluated. If it is true, the body of the loop is executed. If it is false, the body of the loop does not execute and the flow of control jumps to the next statement just after the 'for' loop.

After the body of the 'for' loop executes, the flow of control jumps back up to the increment statement. This statement allows you to update any loop control variables. This statement can be left blank, as long as a semicolon appears after the condition.*/