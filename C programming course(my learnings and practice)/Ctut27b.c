#include <stdio.h>
int main()
{
    int arr[]={12,21,34,45,59,61,73};
    printf("Value at position 0 of the array is %d\n", arr[0]);
    printf("Value at position 1 of the array is %d\n", arr[1]);
    printf("Value at position 2 of the array is %d\n\v\v\v", arr[2]);

//The two codes givn below will return the same result
    printf("The address of first element of the array is %d\n", &arr[0]);
    printf("The address of first element of the array is %d\n", arr);
//The two codes given below will also return the same result
     printf("The address of second element of the array is %d\n", &arr[1]);
     printf("The address of second element of the array is %d\n\v\v\v", arr+1);

    // arr++;  this is invalid because it is a constant which takes the address value od arr[0]
    //we can do oone thing that
    //int *arrayptr=arr; then we can write arrayptr++ or arrayptr-- it will be vaild now
    




//Similarly values can also be printed in this way

     printf("The value of the first element of the array is %d\n", *(&arr[0]));
      printf("The value of the first element of the array is %d\n", arr[0]);
     printf("The value  of the first element of the array is %d\n", *(arr));


    printf("The value of the second element of the array is %d\n", *(&arr[1]));
    printf("The value of the second element of the array is %d\n", arr[1]);
     printf("The value of the second element of the array is %d\n", *(arr+1));
    


    return 0;
}