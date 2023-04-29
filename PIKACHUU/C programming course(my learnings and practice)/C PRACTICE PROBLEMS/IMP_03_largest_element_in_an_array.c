#include <stdio.h>
int returnmax(int array[], int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
array[0]=123;
array[1]=4;

    return max;
}

int main()
{
    int arr[] = {14, 12, 26, 98, 21357, 286, 345, 34, 48};
    int maximum = returnmax(arr, 9);//or else a new variable say max can be equated with it and printed next
    printf("The element with the maximum value in the array is : %d\n", maximum); //Call by reference is done in this case
    for (int i = 0; i < 9; i++)
    {
        printf("The %d element of the array is %d\n", i, arr[i]);
    }
    
    return 0;
}                                         //Since base address of array has been passed so any change made 
                                          //in the function will be reflected in the main function
                                          //Though only the address of 0th element of the array is passed to the pointer 
                                          //but changes made in any element of the array in the funtion will be reflected in the main function as well