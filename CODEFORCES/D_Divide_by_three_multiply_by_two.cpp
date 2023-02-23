/*
Trilasha Mazumder
2112063
*/


/// ------------------------------------HEADER-FILES and ABBREVIATIONS---------------------------- ///
#include <bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp> 


using namespace std;
//using namespace __gnu_pbds;

//typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds; 


#define ll                    long long
#define ld                    long double
#define pb                    push_back
#define popb                  pop_back
#define lb                    lower_bound
#define ub                    upper_bound
#define umap                  unordered_map
#define uset                  unordered_set
#define ff                    first
#define ss                    second
#define pi                    pair<ll,ll> 
#define maxpq                 priority_queue <ll> pq;
#define minpq                 priority_queue <ll, vector<ll>, greater<ll> > pq; 
/// ------------------------------------PRE-DEFINED VALUES---------------------------------------- ///
#define mod                   1000000007
#define PI                    3.141592653589793238
#define bpl(n)                __builtin_popcountll(n);
/// ------------------------------------TAKING INPUTS--------------------------------------------- ///
#define inp(n)                ll n;cin>>n;
#define inpv(v)               for(auto &x: v) cin>>x;
#define make(arr,n)           ll arr[n]; fr(i,n) cin>>arr[i];
/// ------------------------------------FOR LOOPS AND SORT---------------------------------------- ///
#define fr(i,n)               for (ll i=0;i<n;++i)
#define frs(i,k,n)            for(ll i=k;i<n;++i)
#define fA(i,a,n)             for(ll i=a;i<=(n);++i)
#define fD(i,a,n)             for(ll i=a;i>=(n);--i)
#define dsort(arr)            sort(arr,arr+n,greater<ll>())
#define asort(arr)            sort(arr,arr+n)
#define all(str)              str.begin(), str.end()
#define pll                   pair<ll,ll>


/// ------------------------------------NUMBER THEORY--------------------------------------------- ///
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
/*
vector<ll> v= sieve(1e5+10);
TC--> nloglogn
*/

/// ------------------------------------PRINTOUTS------------------------------------------------- ///
#define printv(v)             for(auto &i: v){cout << i << " ";} cout << endl;
#define printmap(mp)          for(auto &i: mp){cout << i.first << " "<<i.second<<endl;}
#define printset(st)          for(auto &i: st){cout << i << " ";} cout << endl;
#define line                  cout<<"----------------------------------------"<<endl;
void google(ll t) {cout << "Case #" << t << ": ";}

/// ---------------------------------------------------------------------------------------------- ///
//  v[i]=pow(10,v[i])+0.1; 
//max 1e7 size vector can be created
///vector<vector<int>> M;
//int m = number of rows, n = number of columns;
//M.resize(m, vector<int>(n));


vector<ll> v;
vector<ll> ans;
set<ll> st;

void dfs(ll val)
{
    if(val%3==0 && st.find(val/3)!=st.end())
    {
        ans.pb(val/3);
        st.erase(val/3);
        dfs(val/3);
    }
    else if(st.find(val*2)!=st.end())
    {
        ans.pb(val*2);
        st.erase(val*2);
        dfs(val*2);
    }
}

void solve()
{
    inp(n);
    v.resize(n);
    inpv(v);

    
    fr(i,n)
    st.insert(v[i]);

    ll start=-1;

    sort(all(v),greater<ll>());

    fr(i,n)
    {
        if(v[i]%2 && v[i]%3==0)
        {
            start=v[i];
            break;
        }
    }

    if(start==-1)
    {

    sort(all(v));
    fr(i,n)
    {
        if(v[i]%2==0 && v[i]%3==0 && st.find(v[i]/2)==st.end() && st.find(v[i]*3)==st.end())
        {
            start=v[i];
            break;
        }
    }
    }

    if(start!=-1)
    {
        ans.pb(start);
        st.erase(start);
        dfs(start);
    }
    else
    {
        sort(all(v));
        auto it=st.begin();
        start=*it;
        ans.pb(start);
        st.erase(start);
        dfs(start);
    }


    printv(ans);


}
    
int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);
    
ll q=1;
//cin>>q;
for(ll i=0;i<q;i++){
   // google(i+1);
    solve();
}
    return 0;
}


































