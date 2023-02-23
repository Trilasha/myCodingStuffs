//{ Driver Code Starts
//Initial function template for C++
//refer to striver's sheet for furtherinformation on TC and SC




#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int partition(int arr[],int left,int right,int k)
    {
        int pivot=arr[left];
        int l=left+1;
        int r=right;
        
        while(l<=r)
        {
            if(arr[l]>pivot && arr[r]<pivot)
            {
                swap(arr[l],arr[r]);
                l++;
                r--;
            }
            
            if(arr[l]<=pivot)
            l++;
            
            if(arr[r]>=pivot)
            r--;
        }
        
        swap(arr[left],arr[r]);
        return r;
    }
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        int left=0;
        int right=r; 
        int ans=-1;
        while(1){
            int idx=partition(arr,left,right,k);
            if(idx==k-1)
            {
                return arr[idx];
            }
            else if(idx<k-1)
                 left=idx+1;
            else
                 right=idx-1;
        }
        
    }
};

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends