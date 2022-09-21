#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("File name is %s\n", __FILE__);  //Here FILE is a predefined macro
    printf("Today's date is %s\n", __DATE__);
    printf("Time now is %s\n", __TIME__); //For time we are using %s
    printf("Line number is %d\n", __LINE__);
    printf("ANSI: %d\n", __STDC__); //as per the output it is compiled by ANSI standards
    return 0;
}