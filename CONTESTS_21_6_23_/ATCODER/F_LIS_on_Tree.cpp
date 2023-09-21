/* Trilasha Mazumder */

#include <bits/stdc++.h>
using namespace std;
           
#define ll                    long long
#define ld                    long double
#define pb                    push_back
#define lb                    lower_bound
#define ub                    upper_bound
#define ff                    first
#define ss                    second
#define maxpq                 priority_queue <ll> pq;
#define minpq                 priority_queue <ll, vector<ll>, greater<ll> > pq; 
#define inpv(v)               for(auto &x: v) cin>>x;
#define fr(i,n)               for (ll i=0;i<n;++i)
#define all(str)              str.begin(), str.end()
#define pll                   pair<ll,ll>
#define printv(v)             for(auto &i: v){cout << i << " ";} cout << endl;
#define printmap(mp)          for(auto &i: mp){cout << i.first << " "<<i.second<<endl;}
#define printset(st)          for(auto &i: st){cout << i << " ";} cout << endl;
#define line                  cout<<"----------------------------------------"<<endl;
#define arrow                 cout<<"--->";
#define debugmap(mp)          for(auto &i: mp){cout << i.ff << "-->" << i.ss <<endl;} cout << endl;
#define debugset(st)          for(auto &i: st){cout << i << " ";} cout << endl;
#define fast_io               ios_base::sync_with_stdio(false);cin.tie(NULL);
#define sp(x)                 fixed<<setprecision(x)
#define PI                    3.141592653589793238
#define bpl(n)                __builtin_popcountll(n);
#define md                    998244353
#define modval                1000000007
//#define endl                " \n"
/*----------------------------------------------------------------------------------------------------------- */




vector<ll> ans;

void dfs(ll node,ll parent,vector<vector<ll>> &adj,vector<ll> &v,vector<ll> &temp,vector<ll> &ans){
    for(auto &i:adj[node]){
        if(i!=parent){
            ll ok=0;ll val=-1;ll ind=-1;
            if(temp.back()<v[i-1]){
                ok=1;
                temp.push_back(v[i-1]);
            }else{
                ok=2;
                ind=lb(all(temp),v[i-1])-temp.begin();
                val=temp[ind];
                temp[ind]=v[i-1];
            }
            ans[i]=temp.size();
            dfs(i,node,adj,v,temp,ans);
            if(ok==1){
                temp.pop_back();
            }else if(ok==2){
                temp[ind]=val;
            }
        }
    }
}
void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    inpv(v);
    ans.resize(n+1);
    vector<vector<ll>> adj(n+1);
    for(ll i=0;i<n-1;i++){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vector<ll> temp;
    temp.pb(v[0]);
    ans[1]=1;
    dfs(1,-1,adj,v,temp,ans);
    for(ll i=1;i<=n;++i){
        cout<<ans[i]<<endl;
    }

}


int main(){

fast_io;

ll q=1;
//cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}







   
