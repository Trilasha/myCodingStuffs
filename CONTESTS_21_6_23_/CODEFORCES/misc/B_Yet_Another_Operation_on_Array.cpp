/*
    "When you are in darkness, listen to the whispers of your heart
    but when you are in light, listen to the thunder of your brain."
    
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
/*----------------------------------------------------------------------------------------------------------- */



/*
0110
1110
0010
0011
0111
0110


001
001
001
010
011
*/

void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    inpv(v);
    if(n==1){
        cout<<0<<endl;
        return;
    }
    ll ans=0;
    ll l=-1,r=-1;
    for(ll i=30;i>=0;--i){
        ll s=-1,e=-1;
        for(ll j=0;j<n;++j){
            if(!(v[j]&(1LL<<i))){
                s=j+1;
                break;
            }
        }
        for(ll j=n-1;j>=0;--j){
            if(!(v[j]&(1LL<<i))){
                e=j+1;
                break;
            }
        }
        ll one=0;
        for(ll j=0;j<n;++j){
            if(v[j]&(1LL<<i)){
                one=1;
                break;
            }
        }
        if(s==-1 || !one || (e-s+1)==n) continue;
        if(l==-1){
            l=s;
            r=e;
        }else{
            ll oril=l;
            ll orir=r;
            l=min(l,s);
            r=max(r,e);
            if((r-l+1)==n){
                l=oril;
                r=orir;
            }
        }
    }
    cout<<((l==-1)?0:r-l+1)<<endl;
 
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



vector<ll> dijkstra(vector<vector<pair<int,int>>> &adj,int n,int S){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<ll> dis(n + 1, 1e18);
    vector<ll> parent(n + 1);
 
    for (ll i = 1; i <= n; ++i)
        parent[i] = i;
 
    dis[S] = 0;
    pq.push({0, S});
 
    while (!pq.empty()){
        ll distance = pq.top().first;
        ll node = pq.top().second;
        pq.pop();

        //trying to add the set erase functionality somehow (though tc remains the same for both pq and set)
        if(distance>dis[node]) continue;

        for (auto &i : adj[node])
        {
            ll childNode = i.first;
            ll edgeWeight = i.second;
            if (distance + edgeWeight < dis[childNode])
            {
                dis[childNode] = distance + edgeWeight;
                pq.push({dis[childNode], childNode});
                parent[childNode] = node;
            }
        }
    }
  return dis;
}


struct segtree{
    vector<ll> v;ll id=0,sz;//id for initialization
    segtree(ll _n){sz=1;while(sz<_n){sz<<=1;}v.assign(2*sz,id);}
    ll func(ll x,ll y){ return x+y;}
    void pull(ll x){ v[x]=func(v[2*x+1],v[2*x+2]);}
    void update(ll i, ll val, ll x, ll lx, ll rx){ // 0-based indexing 
        if(rx-lx==1){ v[x]=val; return;}
        ll m=(lx+rx)/2;
        if(i<m){update(i,val,2*x+1,lx,m);}
        else{update(i,val,2*x+2,m,rx);}
        pull(x);
    }
    void update(ll i, ll val){ update(i,val,0,0,sz);}
    ll query(ll l,ll r,ll x,ll lx,ll rx){ // [l,r) l->INCLUSIVE/ r->EXCLUSIVE
        if(lx>=r || l>=rx) return id;
        if(lx>=l && rx<=r) return v[x];
        ll m=(lx+rx)/2;
        ll s1=query(l,r,2*x+1,lx,m);
        ll s2=query(l,r,2*x+2,m,rx);
        return func(s1,s2);
    }
    ll query(ll l,ll r){ return query(l,r,0,0,sz);}
};

segtree st(n);
for(ll i=0;i<n;++i){
    st.update(i,v[i]);
}