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




void solve(){
    ll v,e;
    cin>>v>>e;
    vector<vector<ll>> adj(v+1);
    fr(i,e){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    set<ll> odd,even;
    queue<pll> q;
    vector<ll> vis(v+1,0);
    q.push({1,0});
    while(!q.empty()){
        // ll sz=q.size();
        // while(sz--){
            auto it=q.front();
            q.pop();
            ll node=it.ff;
            ll level=it.ss;
            if(vis[node])continue;
            if(level%2==0){
                even.insert(node);
            }else{
                odd.insert(node);
            }
            vis[node]=1;
            for(auto i: adj[node]){
                if(!vis[i]){
                    q.push({i,level+1});
                }
            // }
        }
    }
    if(odd.size()<=(v/2)){
        cout<<odd.size()<<endl;
        for(auto i: odd){
            cout<<i<<" ";
        }
        cout<<endl;
    }else{
        cout<<even.size()<<endl;
        for(auto i: even){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}


int main(){

fast_io;

ll q=1;
cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}


