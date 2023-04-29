#include <stdio.h>
void printPayment(int amount)
{
int n1,n10,n50;
n50=(amount/50);
amount=amount - (50*n50);
n10=(amount/10);
amount=amount -(10*n10);
n1=amount;
printf("Number of notes of 1,10 and 50 denominations are: ");
printf("%d,%d and %d respectively",n1,n10,n50);
}
int main()
{
    int amount;
    printf("Enter the amount:\n");
scanf("%d",&amount);
printPayment(amount);
    return 0;
}