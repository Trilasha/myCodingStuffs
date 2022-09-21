/* To show the second type*/

#include <stdio.h>

void func(int* ptr)
{
    for (int i = 0; i < 4; i++)
    {
    printf("The value at %d is %d\n", i, *(ptr+i));  //instead of ptr[i],we can also write *(ptr+i)
    }
    *(ptr+2)=345;  //Suppose we change a value and then again call the function,now look at the change
      return; 
}

int main()
{
    int arr[]={12,14,16,18};
    func(arr);
    func(arr);
    return 0;
}