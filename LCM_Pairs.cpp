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





void divisors(ll n)
{
for (ll i = 1; i*i <=n; i++)
{
if(n%i==0)
{
cout<<i<<" ";
if(i!=n/i)
cout<<n/i<<" ";
}
}
}

void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    inpv(v);
    sort(all(v));
    map<ll,ll> mp;
    ll ans=0;
    for(ll i=0;i<n;++i){
        for (ll j = 1; j*j <=v[i]; j++){
            if(v[i]%j==0){
                ans+=mp[j];
                if(j!=v[i]/j){
                    ans+=mp[v[i]/j];
                }
            }
        }
        mp[v[i]]++;
    }
    cout<<ans<<endl;
}
int main(){

fast_io;

ll q=1;
// cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}




class BIT{
    vector<ll> bit;
public:
    BIT(ll n)
    {
        bit.resize(n+1,0);
    }
    void update(ll x, ll val,ll n)
    {
        for(; x <= n; x += x&-x)
            bit[x] += val;
    }
    ll query(ll x)
    {
        ll sum = 0;
        for(; x > 0; x -= x&-x)
            sum += bit[x];
        return sum;
    }
};
//BIT bt(n);
//for(ll i=1;i<=n;++i){
//bt.update(i,temp[i],n);
//1-based indexing so input in vector from 1 to <=n
