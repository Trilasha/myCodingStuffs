#include <stdio.h>
void arrayrev(int arr[])
{
    int a;
    for (int i = 0; i < 7/2; i++)
    {
        a = arr[i];
        arr[i] = arr[6 - i];
        arr[6 - i] = a; 
       // printf("%d\t", a);                               //UNABLE TO FIGURE OUT THE PROBLEM!!!!!!!!!
    }
   
}

int main()
{
    int arr[7] = {12, 21, 34, 45, 52, 61, 93};
    arrayrev(arr);
   for (int i = 0; i < 7; i++)
   {
      printf("%d\t",arr[i]);
   }
   
    return 0;
}
//Solution by Harry sir is given in Ctut40.c