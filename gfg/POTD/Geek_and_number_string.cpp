//{ Driver Code Starts
//Initial template for C++
 
#include<bits/stdc++.h>
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{
public:
    int minLength(string s, int n) {
        stack<char> st;
        for(int i=0;i<n;++i)
        {
            if( ((s[i]+1==s[i+1] && s[i]%2!=0) || (s[i+1]+1==s[i]) && s[i]%2==0) || (s[i]=='0' && s[i+1]=='9')||(s[i]=='9'&&s[i+1]=='0'))
            {
                s[i]='*';
                s[i+1]='*';
                i++;
            }
            else
            {
            if(st.empty())
            st.push(s[i]);
            else if(((s[i]+1==st.top() && s[i]%2!=0) || (st.top()+1==s[i]) && s[i]%2==0) || (s[i]=='0' && st.top()=='9')||(s[i]=='9'&&st.top()=='0'))
            st.pop();
            else
            st.push(s[i]);
            }
            
        }
        return st.size();
    } 
};


//{ Driver Code Starts.

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        Solution obj;
        cout << obj.minLength(s, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends