// /// ------------------------------------HEADER-FILES and ABBREVIATIONS---------------------------- ///
// #include <bits/stdc++.h>
// using namespace std;
// #define ll                    long long
// #define ld                    long double
// #define pb                    push_back
// #define popb                  pop_back
// #define lb                    lower_bound
// #define ub                    upper_bound
// #define umap                  unordered_map
// #define uset                  unordered_set
// #define ff                    first
// #define ss                    second
// #define pi                    pair<ll,ll> 
// #define maxpq                 priority_queue <ll> pq;
// #define minpq                 priority_queue <ll, vector<ll>, greater<ll> > pq; 
// /// ------------------------------------PRE-DEFINED VALUES---------------------------------------- ///
// #define maxval                1000000007
// #define PI                    3.141592653589793238
// #define bpl(n)                __builtin_popcountll(n);
// /// ------------------------------------TAKING INPUTS--------------------------------------------- ///
// #define inp(n)                ll n;cin>>n;
// #define inpv(v)               for(auto &x: v) cin>>x;
// #define make(arr,n)           ll arr[n]; fr(i,n) cin>>arr[i];
// /// ------------------------------------FOR LOOPS AND SORT---------------------------------------- ///
// #define fr(i,n)               for (ll i=0;i<n;++i)
// #define frs(i,k,n)            for(ll i=k;i<n;++i)
// #define fA(i,a,n)             for(ll i=a;i<=(n);++i)
// #define fD(i,a,n)             for(ll i=a;i>=(n);--i)
// #define dsort(arr)            sort(arr,arr+n,greater<ll>())
// #define asort(arr)            sort(arr,arr+n)
// #define allasort(str)         sort(str.begin(), str.end())
// #define alldsort(str)         sort(str.begin(), str.end(),greater<char>())
// #define all(str)              str.begin(), str.end()
// #define pll                   pair<ll,ll>
// /// ------------------------------------PRINTOUTS------------------------------------------------- ///
// #define printv(v)             for(auto &i: v){cout << i << " ";} cout << endl;
// #define printmap(mp)          for(auto &i: mp){cout << i.first << " "<<i.second<<endl;}


// /// ---------------------------------------------------------------------------------------------- ///
// //ceil(log2(x))
    
// /// ---------------------------------------------------------------------------------------------- ///
    



// void solve(){
//    inp(n);
//    vector<ll> v(n);
//    inpv(v);
//    vector<ll> ans;
//    ans.pb(v[0]);
//    ll temp=0;
//    ll var=0;
//    ll index=v[0];
//    for(ll i=1;i<n;++i)
//    {
//     temp=index+v[i];
//     var=index-v[i];
//     if(temp>=0 && var>=0 && temp!=var)
//     {
//         cout<<temp<<" "<<var<<endl;
//         cout<<-1<<endl;
//         return;
//     }
//     else
//     {
//         if(temp>=0)
//         {
//             ans.pb(temp);
//             index=temp;
//         }
//         else if(var>=0)
//         {
//             ans.pb(var);
//             index=var;
//         }
//     }
//    }
//    printv(ans);
// }
    
// int main(){

// ios_base::sync_with_stdio(false);
// cin.tie(NULL);

    
// ll q;
// cin>>q;
// while(q--)
// {
//     solve();
// }
//     return 0;
// }






// /*
// //
// string s=to_string(bitset<64> b(10));

// //
// using namespace std;
// const ll N=1e9+10;
// vector<ll> g[N];
// bool vis[N];
// void dfs(ll vertex)
// {
// vis[vertex]=true;
// for(ll child:g[vertex])
// {
//     if(vis[child])continue;
//     dfs(child);
// }
// }
// */

// Darpan Deka
// NIT Silchar

// Om Namah Shivay
// Jai Shree Ram

// INDIA
// Real Madrid

#include<bits/stdc++.h>
using namespace std;
#define raftaar ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define fr(x,y) for(ll x=0; x<y; x++)
#define fr1(x,t,y) for(ll x=t; x<y; x++)
#define fr3(x,t,y) for(ll x=t; x>y; x--)
#define ga(a,n) ll a[n]; fr(i,n) cin>>a[i];
#define gv(v,n) vll v(n); fr(i,n) cin>>v[i];
#define vll vector <ll>
#define vp vector<pair<ll,ll>>
#define pb push_back
#define pp pop_back
#define all(vector) vector.begin(), vector.end()
#define nn endl;

void OM(){
    ll n;
    cin>>n;
    ga(a,n);
    vll v(n);
    v[0] = a[0];
    for(ll i=1; i<n; i++){
        if(a[i] > 0 && a[i] < v[i-1]){
            cout<<-1<<endl;
            return;
        }
        else{
            v[i] = v[i-1] + a[i];
        }
    }
    fr(i,n){
        cout<<v[i]<<" ";
    }
    cout<<endl;

}

int main(){
    ll football;
    cin>>football;
    while(football--){
        OM();
    }
}