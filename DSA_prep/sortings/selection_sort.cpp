 void selectionSort(int arr[], int n)
    {
       //code here
       int minindex;
       for(int i=0;i<n;++i)
       {
           minindex=i;
           for(int j=i+1;j<n;++j)
           {
              if(arr[j]<arr[minindex]) 
              minindex=j;
           }
           swap(arr[i],arr[minindex]);
       }
    }
//TC-->O(n^2)
//SC-->O(1)

//smallest one comes first then the second smallest and so on




//inplace
//stable selection sort available
