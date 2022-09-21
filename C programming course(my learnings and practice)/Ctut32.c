/* To show first type */



#include <stdio.h>

int func1(int array[]) //same name arr can be written or diferent like array also
{
    for (int i = 0; i < 4; i++)
    {
        printf("The value at %d is %d\n", i, array[i]);
    }
    array[0]=385;                                 //if this line is written then as said earlier,the change will get reflected in the main function
    return 0;                                     //kind of call by reference because pointers are created
}
    int main()
    {
        int arr[] = {12, 134, 16, 18};
        printf("The value at index 0 is %d\n", arr[0]);
        func1(arr);    
       printf("The value at index 0 is %d\n", arr[0]);                       //which type of calling is this?
        return 0;
    }