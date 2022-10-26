void selectionSort(int arr[], int n)
    {
      int minindex;
      for(int i=0;i<n;++i)
      {
          minindex=i;
          for(int j=i+1;j<n;++j)
          {
              if(arr[j]<arr[minindex])
              minindex=j;
          }
          int key=arr[minindex];
          while(minindex>i)
          {
              arr[minindex]=arr[minindex-1];
              minindex--;
          }
          arr[i]=key;
      }
    }