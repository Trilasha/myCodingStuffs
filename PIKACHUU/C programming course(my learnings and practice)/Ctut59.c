//3 things have been shown

#include <stdio.h>
#include "Ctut53.c" //Error will be shown since we have included two main functions unless we make it main2 in Ctut53.c
#define PI 3.14
#define SQUARE(r) r*r


int main()
{
    //int var=0;
    float var = PI;
    printf("This is me %f\n", var);

int r=4;
    printf("The area of the circle is %f\n", PI*SQUARE(r));  //If value is integer and %d is given then wrong result will appear
    return 0;
}