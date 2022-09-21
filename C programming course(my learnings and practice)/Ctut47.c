#include <stdio.h>
#include <stdlib.h> //All this comes under stdlib.h

int main()
{
    //use of malloc
    int *ptr;
    int n;
    printf("Enter the size of the array you want to create\n");
    scanf("%d", &n);              //Don't give \n after %d otherwise problem will arise as had happened once

    ptr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value no.%d of this array\n", i); //Dynamically allocated array can be written like this
        scanf("%d", &ptr[i]);                               //*(ptr+i)=ptr[i]
    }

    for (int i = 0; i < n; i++)
    {
        printf("The value at %d of this array is %d\n", i, ptr[i]);
       
    }

        return 0;
    }