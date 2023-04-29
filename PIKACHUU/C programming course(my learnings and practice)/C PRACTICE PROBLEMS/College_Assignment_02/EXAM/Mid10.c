//Incomplete
#include <stdio.h>
int main()
{
    int d, f;
    int n = 7, i, x[10] = {3, 7, 5, 2, 4, 6, 1};
    d = x[0];
    f = x[1];
    if (d < f)
    {
        i = d;
        d = f;
        f = i;
    }
    for (i = 2; i < n; i++)
    {
        if (x[i] < f)
        {
            d = f;
            f = x[i];
        }
        else if (x[i] < d)
        {
            d = x[i];
        }
        printf("%d", d);
    }

    return 0;
}