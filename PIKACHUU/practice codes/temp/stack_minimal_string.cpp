/// ------------------------------------HEADER-FILES and ABBREVIATIONS---------------------------- ///
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define popb pop_back
#define lb lower_bound
#define up upper_bound
#define umap          unordered_map
#define uset          unordered_set
/// ------------------------------------PRE-DEFINED VALUES---------------------------------------- ///
#define md                  10000007
#define PI          3.141592653589793238
/// ------------------------------------TAKING INPUTS--------------------------------------------- ///
#define inp(n)              ll n;cin>>n;
#define inpv(v)              for(auto &x: v) cin>>x;
#define make(arr,n)   ll arr[n]; f(i,n) cin>>arr[i];
/// ------------------------------------FOR LOOPS AND SORT---------------------------------------- ///
#define fr(i,n)             for (ll i=0;i<n;++i)
#define fA(i,a,n)   for(ll i=a;i<=(n);++i)
#define fD(i,a,n)   for(ll i=a;i>=(n);--i)
#define dsort(arr)            sort(arr,arr+n,greater<ll>())
#define asort(arr)            sort(arr,arr+n)
#define allasort(str)             sort(str.begin(), str.end())
#define alldsort(str)              sort(str.begin(), str.end(),greater<char>())
#define all            str.begin(), str.end()
/// ------------------------------------OTHERS--------------------------------------------------- ///
#define ub(a,x)     upper_bound(all(a), x)
#define ps(x,n)     fixed<<setprecision(n)<<x

    
    
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    string s;
    cin>>s;
    multiset<char> ms;
    stack<char> st;
    string ans="";
    for (ll i = 0; i < s.size(); i++)
    {
        ms.insert(s[i]);
    }
    for (ll i = 0; i < s.size(); i++)
    {
        st.push(s[i]);
        ms.erase(ms.find(s[i]));
       // while(ms.size()!=0 && st.top() <= *ms.begin() && !st.empty() )
        while(!st.empty() && st.top() <= *ms.begin())
        {
            ans.pb(st.top());
            st.pop();
        }
    }
    if(st.empty())
    {
        cout<<ans<<endl;
        
    }
    else
    {
        while (!st.empty())
        {
          ans.pb(st.top());
            st.pop();
        }
         cout<<ans<<endl;
    }
    // while(!s.empty())
    // {
    //      ans.pb(st.top());
    //        st.pop();
    // }
    //     cout<<ans<<endl;

/*  
********UNDERSTANDING OF LINENOS:-51 AND 52*********    
multiset<char> st;
cout<<st.begin()<<endl;
//gets successfully executed

stack<char> st;
cout<<st.top()<<endl;
//SIGSEGV(returns runtime error)
*/

//*********LEARNINGS FROM THE QUESTION*********
//https://codeforces.com/contest/797/submission/159324189
    return 0;
}