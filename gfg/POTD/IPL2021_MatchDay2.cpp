//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        vector<int> ans;
        deque<int> d(k);
        for(int i=0;i<k;++i)
        {
            while(!d.empty() && arr[i]>=arr[d.back()])
            d.pop_back();
            d.push_back(i);
        }
        // 3 2 1 4 6 2 1---> k==7-->3 2 1 then 4 then 6 then 6 2 then 6 2 1 
        //the foremost element is the maximum one
        for(int i=k;i<n;++i)
        {
            //check whether the indices will fit in the current window or not
            //accordingly the maximum(till now)might get removed if its index
            //does not fit in the current window
            ans.push_back(arr[d.front()]);
            while(d.empty()==0 && d.front()<=i-k)
            d.pop_front();
            while(d.empty()==0 && arr[i]>=arr[d.back()])
            d.pop_back();
            d.push_back(i);
        }
         ans.push_back(arr[d.front()]);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends