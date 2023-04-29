#include <stdio.h>
int main()
{
    //****************Method number 1(Myself)*********************
    //Runs in linear time
    // int num, sum = 0; //sum=0 is must
    // printf("Enter the last natural number upto which you want the sum:\n");
    // scanf("%d", &num);
    // for (int i = 1; i < num + 1; i++)
    // {
    //     sum += i;
    // }

    // printf("The sum of the first %d natural numbers is %d\n", num, sum);

    //But when n tends to infinity,the program will run very slowly so there is an another alternative method for the same





    //*********************Method number 2(Harry bhai)********************
    //Using constant time running algorithm
    //Runs in constant time

    int num2, sum2;
    printf("Enter the last natural number upto which you want the sum:\n");
    scanf("%d", &num2);
    sum2 = num2 * (num2 + 1) / 2;
    printf("The sum of the first %d natural numbers is %d\n", num2, sum2);
    return 0;
}