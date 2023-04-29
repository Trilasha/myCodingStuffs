
/*
You manage a travel agency and you want your n drivers to input their followwing details:
1.Name
2.Driving License
3.Route
4.kms
your program should be able to take n as the inputand your drivers will start inputting their details one by one
Your program should print the details of the drivers in a detailed fashion
User structures(You cannot make variables)
FOR THE TIME BEING TAKE N=3 SINCE DYNAMIC MEMORY ALLOCATION IS YET TO BE LEARNT
*/
#include <stdio.h>
#include <string.h>

struct drivers
{
    char name[34];
    int no;
    char route[61];
    float kms;
};
        
int main()                      //IF THIS SUM IS DONE USING FOR LOOP THEN STRUCTURES WILL BE OF NO USE!
{
    struct drivers d1, d2, d3;
    for (int i = 1; i < 4; i++)
    {
        printf("Driver no. %d is asked to enter the following details:\n", i);
        printf("Please enter your name\n");
        char str1[34];
        gets(str1);

        printf("Enter your route\n");
        char str2[61];
        gets(str2);

        printf("\n");
    }

    return 0;
}