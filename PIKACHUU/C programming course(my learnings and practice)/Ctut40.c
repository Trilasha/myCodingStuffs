\//Solution by Harry sir to Ctut36.c//
#include <stdio.h>

void arrayrev(int arr[])
{
    int temp;
    for (int i = 0; i < 7/2; i++)      //Here 3.5 will be taken as 3 since integer value is considered
    {                                  //Technique for swaping array elements when the total number is odd      
                                       //swap element i with the element 6-i    
        temp = arr[i];                 //Since arrays operate via CALL BY REFERENCE so any change made here will be reflected in the main function       
         arr[i] = arr[6 - i];
         arr[6-i]=temp;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 67};
    printf("Before reversing the array\n");

    for (int i = 0; i < 7; i++)
    {
        printf("The value of element %d is %d\n", i, arr[i]);
    }
    printf("\v");

    arrayrev(arr);
    printf("After reversing the array \n");

    for (int i = 0; i < 7; i++)
    {
        printf("The value of element %d is %d\n", i, arr[i]);
    }

    return 0;
}
