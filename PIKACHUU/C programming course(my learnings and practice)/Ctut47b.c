#include <stdio.h>
#include <stdlib.h>

int main()
{
    //use of calloc
    int *ptr;
    int n;
    printf("Enter the size of the array you want to create\n");
    scanf("%d", &n);             //Don't give \n after %d otherwise problem will arise as had happened once

    ptr = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)                                     //If we comment out linos.13 to 17 then it will show 0
   {
        printf("Enter the value no.%d of this array\n", i);   //Better not to give \n while using loop
       scanf("%d", &ptr[i]);                               
    }

    for (int i = 0; i < n; i++)
    {
        printf("The value at %d of this array is %d\n", i, ptr[i]);
    }

    return 0;
}