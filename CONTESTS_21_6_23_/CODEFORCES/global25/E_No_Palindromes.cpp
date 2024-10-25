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






ll radix=31;
ll mod=1e9+7;
 
vector<ll> hash1,bhash,power1(5e6+30,1);
void precal(string &s){
    int n=s.size();
    hash1.resize(n+5);
    ll a=1;
    for(int x=0;x<n;++x){
        hash1[x+1]=(hash1[x]+(s[x])*a)%mod;
        a=(a*radix)%mod;
    }
}
void preInv(){
    for(int i=1;i<=5e6+10;i++){
        power1[i]=(power1[i-1]*radix)%mod;
    }
}
void back_precal(string &s){
    int n=s.size();
    bhash.resize(n+3);
    ll a=1;
    for(int x=n;x>=1;--x){
        bhash[x]=(bhash[x+1]+(s[x-1])*a)%mod;
        a=(a*radix)%mod;
    }
}
ll back_calc(ll left,ll right){
    ll val=(bhash[left]-bhash[right+1]+mod)%mod;
    return val;
}

void solve(){
    string s;
    cin>>s;
    ll n=s.size();
    preInv();
    precal(s);
    back_precal(s);
    ll ans=1;
    vector<ll> mp(n+3);
    mp[1]=1;
    for(ll i=1;i<n;++i){
        ll ind=i+1;
        ll half=ind/2;
        ll left=(hash1[half]*power1[n-ind])%mod;
        if(ind%2)half++;
        ll right=back_calc(half+1,ind);
        if(left!=right){
           half=(ind+n)/2;
           left=(hash1[])
        }
        ans+=mp[ind];
    }
    // cout<<ans<<endl;
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