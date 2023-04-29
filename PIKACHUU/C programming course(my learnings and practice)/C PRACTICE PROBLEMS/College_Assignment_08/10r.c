//***Code for Q10***
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
union info{
    char str[30];
    int a;
    float b;
};

int main()
{
    union info i1;
    union info *i2;
i2=(union info *)malloc(sizeof(union info));
i1.b=153;
strcpy(i2->str,"TRILASHA MAZUMDER");
printf("i1 float value: %f\n",i1.b);
printf("i2 string value : %s\n",i2->str);
    return 0;
}