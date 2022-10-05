//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long> ans;
          stack<int> s;
        s.push(arr[0]);
        for(int i=1;i<n;++i)
        {
            if(s.empty())
            {
                s.push(arr[i]);
            }
            else
            {
                while(!s.empty() && s.top()<arr[i])
                {
                    ans.push_back(arr[i]);
                    s.pop();
                }
                s.push(arr[i]);
            }
        }
        while(!s.empty())
        {
            ans.push_back(-1);
            s.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends

/////////////////////
/*
Time Complexity: O(N) 
Auxiliary Space: O(N) 
*/
////////////////////