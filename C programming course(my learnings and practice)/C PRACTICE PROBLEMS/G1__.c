#include <stdio.h>
int main()
{
    int side;
    printf("Enter side of the square\n");
    scanf("%d", &side);
    printf("Area of square is %d", area(side));
    return 0;
    
}
int area(int side)
{
    int area = side*side;
    return area;

}


