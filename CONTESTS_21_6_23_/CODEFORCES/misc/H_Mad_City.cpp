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
    ll n,m,v;
    cin>>n>>m>>v;
    vector<vector<ll>> adj(n+1);
    map<ll,ll> mp;
    fr(i,n){
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    vector<ll> par(n+1),col(n+1);
    vector<set<ll>>cycle;

    function<void(ll,ll)> dfs=[&](ll node, ll p){
        col[node]=1;
        par[node]=p;
        for(auto child:adj[node]){
        if(col[child]==0){
            dfs(child,node);
        }else if(col[child]==1 && child!=p){
            set<ll>st;
            ll cur=node;
            st.insert(cur);
            while(cur!=child){
                // cerr<<cur<<" ";
                cur=par[cur];
                st.insert(cur);
            }
            st.insert(child);
            cycle.pb(st);
        } 
        }
        col[node]=2;
    };

    for(int i=1;i<=n;i++){
        if(col[i]==0) dfs(i,i);
    }

    // for(auto &i:cycle[0]){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    // line
    vector<ll> M(n+1,1e18),V(n+1,1e18);
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push({0,v});
    while(!pq.empty()){
        pll p=pq.top();
        pq.pop();
        ll d=p.ff;
        ll node=p.ss;
        if(V[node]<d)continue;
        V[node]=d;
        for(auto &child: adj[node]){
            if (V[child]>d+1){
                pq.push({d+1,child});
            }
        }
    }
    ll node=0,dis=1e18;
    for(ll i=1;i<=n;++i){
        if(cycle[0].count(i)){
            if(V[i]<dis){
                dis=V[i];
                node=i;
            }
        }
    }
    pq.push({0,m});
    while(!pq.empty()){
        pll p=pq.top();
        pq.pop();
        ll d=p.ff;
        ll node=p.ss;
        if(M[node]<d)continue;
        M[node]=d;
        for(auto &child: adj[node]){
            if (M[child]>d+1){
                pq.push({d+1,child});
            }
        }
    }
    // cout<<node<<" "<<M[node]<<" "<<V[node]<<endl;
    cout<<((M[node]<=V[node])?"NO":"YES")<<endl;

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

