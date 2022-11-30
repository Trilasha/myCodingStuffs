 public:
    //Function to sort the array using bubble sort algorithm.
    void bubbleSort(int arr[], int n)
    {
        bool swapped=false;
        for(int i=0;i<n-1;++i)
        {
            swapped=false;
            for(int j=0;j<n-i-1;++j)
            {
                if(arr[j]>arr[j+1])
                {
                    swapped=true;
                  swap(arr[j],arr[j+1]);
                }
            }
            if(swapped==0)
            break;
        }

    }
//can be used to count the minimum number of swaps required (when only adjacent swapping is allowed)
////////bool swapped variable is a must


//tc->O(n^2)
//sc->O(1)
//code not got accepted in the gfg ide:(

//the largest one goes to the end then the second largest one and so on