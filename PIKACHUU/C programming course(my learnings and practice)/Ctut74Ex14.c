//Solution by Harry bhaiya
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14

float Edistance(int x1, int y1, int x2, int y2)
{
    int a = (y2 - y1)*(y2 - y1) + (x2 - x1)*(x2 - x1);
    return sqrt(a);//A function of math.h library
}

float areaofCircle(int x1, int y1, int x2, int y2, float (*distance)(int x1, int y1, int x2, int y2))
{
    float b=PI*distance(x1,y1,x2,y2)*distance(x1,y1,x2,y2);
   printf("The area of the circle is %f\n", b);
}

int main()
{
    int x1, x2, y1, y2;
    float dst;
    printf("Enter the x and y values of the first point respectively:-\n");
    scanf("%d %d", &x1, &y1);
    printf("Enter the x and y values of the second point respectively:-\n");
    scanf("%d %d", &x2, &y2);
    dst = areaofCircle(x1, y1, x2, y2, Edistance);
    
    return 0;
}
