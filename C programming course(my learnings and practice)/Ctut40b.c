//Another way of representing the previous program

#include <stdio.h>

void arrayrev(int arr[])
{
    int temp;
    for (int i = 0; i < 7/2; i++)
    {
        temp=arr[i];
        arr[i]=arr[6-i];
      arr[6-i]=temp;   //If we write in vice versa then the output gets affected
    }
    return;
}



void arrayprint(int arr[])
{
    for (int i = 0; i < 7; i++)
    {
        printf("The value of the element at position %d of the array is %d\n", i, arr[i]);
    }
    
}




int main()
{
    int arr[7]={1,2,3,4,5,6,67};
    printf("Before reversing the array:-\n");
    arrayprint(arr);
    printf("\v");
    printf("After reversing the array:-\n");
    arrayrev(arr);
    arrayprint(arr);
    
    return 0;
}