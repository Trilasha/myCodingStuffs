/*
    When talent doesn't work hard then hardwork beats talent...
    ...hardwork always pays off
*/


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
// insead of bpow use shift operators when b=2 to avoid tle 
// do not perform more than one optimal choice/ops in a single step/loop otherwise break your head with WA





void solve(){
    ll n,k;
    cin>>n>>k;
    vector<vector<ll>> pre;
    for(ll i=0;i<k;++i){
        vector<ll> v(n);
        inpv(v);
        if(n>2){
            for(ll j=2;j<n;++j){
                pre.pb({v[j],v[j-1]});
            }
        }
    }
    if(n<=2){
        cout<<"YES"<<endl;
        return;
    }
    vector<vector<ll>> adj(n+1);
    vector<ll> indegree(n+1);
    for(auto &i:pre){
        adj[i[1]].pb(i[0]);
        indegree[i[0]]++;
    }
    queue<ll> q;
    for(ll x=1;x<=n;++x){
        if(indegree[x]==0){
            // cout<<x<<endl;
            q.push(x);
        }
    }
    ll cnt=0;
    while(!q.empty()){
        ll node=q.front();
        q.pop();
        cnt++;
        for(auto &i:adj[node]){
            indegree[i]--;
            if(indegree[i]==0){
                q.push(i);
            }
        }
    }
    cout<<((cnt==n)? "YES":"NO")<<endl;
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

