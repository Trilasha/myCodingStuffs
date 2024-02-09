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
    ll n;
    cin>>n;
    string s;
    cin>>s;
    map<pll,ll> left,right,up;
    vector<vector<ll>> adj(n+1);
    fr(i,n){
        ll x,y;
        cin>>x>>y;
        if(x>0){
            adj[i+1].pb(x);
            adj[x].pb(i+1);
            left[{i+1,x}]=1;
            up[{x,i+1}]=1;
        }
        if(y>0){
            adj[i+1].pb(y);
            adj[y].pb(i+1);
            right[{i+1,y}]=1;
            up[{y,i+1}]=1;
        }
    }

    ll ans=n;
    function<void(ll,ll,ll)> dfs=[&](ll node,ll par,ll opr){
       if(adj[node].size()==1 && node!=1){
            ans=min(ans,opr);
            return;
       }
       for(auto &i:adj[node]){
            if(i!=par){
                if(left.count({node,i})){
                    if(s[node-1]!='L') dfs(i,node,opr+1);
                    else dfs(i,node,opr);
                }else{
                    if(s[node-1]!='R') dfs(i,node,opr+1);
                    else dfs(i,node,opr);
                }
            }
       }
    };
    dfs(1,0,0);
    cout<<ans<<endl;
}


int main(){

fast_io;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

ll q=1;
cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}

