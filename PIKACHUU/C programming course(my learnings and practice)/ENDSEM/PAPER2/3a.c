#include <stdio.h>

int main()
{
    int arr[7]={14,16,18,20,34,57,100};
    int s=sizeof(arr)/sizeof(arr[0]);
int n;
scanf("%d",&n);    
arr[s]=n;
s=sizeof(arr)/sizeof(arr[0]);
 for (int i = 0; i < s; i++)
    {
        for (int j = i + 1; j < s; j++)
        {
            if (arr[i] > arr[j]) // ascending
            {
                int temp;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < s; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}