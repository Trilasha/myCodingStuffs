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
// /// ------------------------------------OTHERS--------------------------------------------------- ///
// //#define lb(a,x)     lower_bound(all(a), x)
#define ub(a,x)     upper_bound(all(a), x)
#define ps(x,n)     fixed<<setprecision(n)<<x

    
    
using namespace std;
void solve(string &s)
{
    stack<char> str;
    string t="";
    string u="";
    ll index=0;
    ll var=0;
    ll check=0;
    ll b=0;
    char smallest;
    while(var<s.size())
    {
        index=var;
    if(index!=(s.size()-1))
    {
        smallest=s[var];
    for (ll i = var+1; i < s.size(); ++i)
    {
        if(s[i]<smallest)
        {
            smallest=s[i];
             index=i;
         }
    }
    }
    for (ll i = var; i <=index; i++)
    {
        str.push(s[i]);
    }
    check=0;
    while (true)
    {
       // check=0;
        if(index!=(s.size()-1))
        {
        // for (ll i = index+1; i < s.size(); i++)
        // {
        //    if(str.top()>s[i])
        //    check=1;
        // }
        // if(check==1)
        // {
        //     var=index+1;
        //     break;
        // }
        if(check==0)
        {
            while(true)
            {
        u.pb(str.top());
        str.pop();
        //b=1;
        if(!str.empty())
        {
        for (ll i = index+1; i < s.size(); i++)
        {
           if(str.top()>s[i])
           {
            check=1;
           break;
           }
        }
        if(check==1)
        break;
        }
        else
        {   
            b=1;
         var=index+1;     
        break;
        }
            }
        }
         if(check==1)
        {
            var=index+1;
            break;
        }
        }
        else
        {
            while (!str.empty())
            {
                u.pb(str.top());
                str.pop();
            }
            var=index+1;
            break;
        }
        // if(s.empty()==1 || b==1)
        // {
        //     var=index+1;
        // break;
        // }
        if(b==1)
        break;
    }
    }
    cout<<u<<endl;
    return;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
string s;
cin>>s;
solve(s);
    return 0;
}