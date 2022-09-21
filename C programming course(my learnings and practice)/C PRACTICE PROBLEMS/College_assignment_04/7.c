//***Code for Q7***
#include <stdio.h>
void func(int x, int y)
{
    static int a;
    int b = 0;
    a++;
    b++;
    printf("The value of x and y are : %d and %d\n", a, b);
}
int main()
{
    int x = 3, y = 4;

    func(3, 4);
    func(3, 4);
    func(3, 4);

    return 0;
}