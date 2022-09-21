/*For multi-dimentional array using type 1 */

#include <stdio.h>

void func(int arr[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("The value at %d,%d is %d\n", i, j, arr[i][j]);
        }
        }
    return;
}

int main()
{
    int arr[2][2] = {{14, 16}, {18, 21}};
    func(arr);
    return 0;
}