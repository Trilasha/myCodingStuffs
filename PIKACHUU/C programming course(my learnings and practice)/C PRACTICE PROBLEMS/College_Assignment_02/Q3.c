//***Code for Q3***
#include <stdio.h>
int main()
{
    float temp, feh;
    printf("Enter the temperature in degree Celsius:\n");
    scanf("%f", &temp);
    feh = (temp * 9 / 5) + 32;
    printf("The corresponding value of the temperature in Fahrenheit scale is %f\n", feh);

    return 0;
}