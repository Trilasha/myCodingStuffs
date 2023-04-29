#include <stdio.h>

int main()
{
    int a=3;                                                          /* float b=54/5;
                                                                        printf("The value of b is %f\n", b);
                                                                        output will be 10.000000(an integer value though float used*/
    float b=(float)54/5; //here in order to get ans in float we have converted 54 from int to float so float/int= float
    printf("The value of a is %f\n", (float)a);   //type1
    printf("The value of b is %f\n", b);          //type2
    return 0;
}
