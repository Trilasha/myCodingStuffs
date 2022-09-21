//***Code for Q2***-->Under MODIFICATION
#include <stdio.h>
int main()
{
    int arr[] = {1, 2, 2, 3, 3,3,4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("The given array is : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    //If >2 copies of an element are present then it will create an ambiguity in the output
    printf("The duplicate elements in the above array are: \n");
    //for (int i = 0; i < n; i++)
    //{
    //    for (int j = i + 1; j < n; j++)
    //    {
    //        if (arr[i] == arr[j])
    //        {
    //            printf("%d ", arr[i]);
    //        }
    //    }
    //}
    
    for (int i = 0; i < n; i++)
    {
        int count=0;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
               count++;
            }
        }
        if(count!=0)
        printf("%d ",arr[i]);
    }
//This will also create ambiguity so we have to actually remove the repeating elements and keep only a single copy of them
    return 0;
}