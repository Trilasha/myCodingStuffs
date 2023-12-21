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
   ll n,m;
   cin>>n>>m;
   vector<ll> v(n);
   inpv(v);
   vector<set<ll>> st(n+1);
   vector<ll> vis(n+1,1);
    for(ll i=0;i<n;++i){
     st[i+1].insert(v[i]);
    }
    while(m--){
        ll a,b;
        cin>>a>>b;
        if(vis[a]==0){
            if(vis[b]==0)cout<<0<<endl;
            else cout<<st[b].size()<<endl;
        }else if(vis[b]==0){
            if(vis[a]==0)cout<<0<<endl;
            else{
                vis[a]=0;
                swap(st[a],st[b]);
                cout<<st[b].size()<<endl;
                if(st[b].size()>0)vis[b]=1;
            }
        }else{
            ll A=st[a].size();
            ll B=st[b].size();
            // if(A<=B){
                vis[a]=0;
                for(auto &i:st[a]){
                    st[b].insert(i);
                }
                // swap(st[a],st[b]);
                cout<<st[b].size()<<endl;
            // }else{
                // vis[a]=0;
                // for(auto &i:st[b]){
                    // st[a].insert(i);
                // }
                // swap(st[a],st[b]);
                // cout<<st[b].size()<<endl;
            // }
        }
    }

}


int main(){

fast_io;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

ll q=1;
// cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}

