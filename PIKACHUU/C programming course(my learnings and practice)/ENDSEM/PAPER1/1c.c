#include <stdio.h>
int main()
{
    int a[]={1,2,3,4,5,6},*iP=a+4;
printf("%d\n",iP[a[iP[-3]]-3]);
    return 0;
}
//Learning-->
/*
I know that arr[x] is the same as *(arr + x). So arr[-2] is *(arr - 2), which seems OK. What do you think?
Ans)This is only valid if arr is a pointer that points to the second element in an array or a later element. Otherwise, it is not valid, because you would be accessing memory outside the bounds of the array. So, for example, this would be wrong:

int arr[10];

int x = arr[-2]; // invalid; out of range
But this would be okay:

int arr[10];
int* p = &arr[2];

int x = p[-2]; // valid:  accesses arr[0]
It is, however, unusual to use a negative subscript.
*/