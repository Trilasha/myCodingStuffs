//*******Code for Q10*******
#include <stdio.h>
int main()
{
    float p, r, t, SI;
    printf("Enter the principle value(in Rs)\n");
    scanf("%f", &p);
    printf("Enter the rate per annum\n");
    scanf("%f", &r);
    printf("Enter the time(in years)\n");
    scanf("%f", &t);
    SI = (p * r * t) / 100;
    printf("The simple interest during the given time period is : Rs %f", SI);
    return 0;
}