#include <stdio.h>
void printPayment(int n)
{
int n1,n10,n50;
n50=n/50;
n-=50*n50;
n10=n/10;
n-=10*n10;
n1=n;
printf("number of notes of 1,10 and 50 denominations are: %d,%d and %d",n1,n10,n50);
printf("--------------------------------------------------------------------------");
}
int main()
{
    int n;
    scanf("%d",&n);
printPayment(n);
    return 0;
}