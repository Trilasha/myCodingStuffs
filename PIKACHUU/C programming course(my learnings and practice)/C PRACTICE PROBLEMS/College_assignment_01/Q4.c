//*******Code for Q4*******
#include <stdio.h>
#define pi 3.14

int main()
{
    float radius, area;
    printf("Enter the radius of the circle whose area is to be calculated:\n ");
    scanf("%f", &radius);
    area = pi * radius * radius;
    printf("The area of the circle with radius %0.1f unit is : %f sq.unit", radius, area);

    return 0;
}