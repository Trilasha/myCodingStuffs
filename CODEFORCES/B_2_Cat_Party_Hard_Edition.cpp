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
//clear adj and visited vector declared globally after each test case 
//if input newly taken then use 'resize' or else 'assign' (for dp and graphs)
//    BINARY SEARCH ~ 2-PNTS ~ DP 
//    reference for sequence(NT) --> oeis.org
//    log2(x)
//    set.lower_bound(x)
//    for mod division --> a/b use a*inverse(b) (don't divide simply)
//    set<ll> adj[n+1]; --> for adjacency list (to handle erasing of elements)
//    gcd(x,y)=gcd(x-y,y) --->  gcd(x,y,z,...)=gcd(x-y,y,z,...)
//    a+b=2⋅(a&b)+a⊕bs
//    a⊕b=¬(a&b)&(a∣b)
/*----------------------------------------------------------------------------------------------------------- */




void solve(){
  ll n;
  cin>>n;
  vector<ll> v(n);
  inpv(v);
  map<ll,ll> mp,cnt;
  fr(i,n){
    mp[v[i]]++;
  }
  set<ll> st;
  for(auto &i: mp){
    cnt[i.ss]++;
    st.insert(i.ss);
  }

  for(ll i=n-1;i>=0;--i){
    //line
    if(mp.size()==1 || mp.size()==(i+1)){
        cout<<i+1<<endl;
        return;
    }

    if(st.size()==2){
        auto it=st.begin();
        ll a=*it;
        it++;
        ll b=*it;
        //cout<<a<<" "<<b<<endl;
        if((a+1==b && cnt[b]==1) || (a==1 && cnt[a]==1)){
            cout<<i+1<<endl;
            return;
        }
    }
    cnt[mp[v[i]]]--;
    if(cnt[mp[v[i]]]==0){
        st.erase(mp[v[i]]);
    }
    mp[v[i]]--;
    if(mp[v[i]]==0){
        mp.erase(v[i]);
    }else{
        cnt[mp[v[i]]]++;
        st.insert(mp[v[i]]);
    }
  }
  cout<<1<<endl;
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






   
vector<ll> dijkstra(vector<vector<pair<ll,ll>>> &adj,int n)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<ll> dis(n + 1, 1e18);
    vector<ll> parent(n + 1);
 
    for (ll i = 1; i <= n; ++i)
        parent[i] = i;
 
    dis[1] = 0;
    pq.push({0, 1});
 
    while (!pq.empty())
    {
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
 