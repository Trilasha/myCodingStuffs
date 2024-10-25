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





ll prime[200010] = { 0 };
ll k[200010] = { 0 };
 
void sieve(){
    for (ll i = 1; i < 200010; i++)
        k[i] = i;
    for (ll i = 2; i < 200010; i++) {
        if (prime[i] == 0)
            for (ll j = i; j < 200010; j += i) {
                prime[j] = 1;
                while (k[j] % (i * i) == 0)
                    k[j] /= (i * i);
            }
    }
}

ll func(vector<ll> &arr, ll n){
    map<ll, ll> freq;
    for (ll i = 0; i < n; i++) {
        freq[k[arr[i]]]++;
    }
 
    ll sum = 0;
 
    for (auto i : freq) {
        sum += ((i.second - 1) * i.second) / 2;
    }
 
    return sum;
}
 
void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    inpv(v);
    vector<ll> arr;
    ll cnt=0;
    ll ans=0;
    fr(i,n){
        if(v[i]==0)cnt++;
        else{
            arr.pb(v[i]);
        }
    }
    ll nn=arr.size();
    ans+=(cnt*(cnt-1))/2;
    ans+=cnt*nn;
    ans+=func(arr,arr.size());
    cout<<ans<<endl;
 
}


int main(){

fast_io;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

ll q=1;
// cin>>q;
sieve();
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}

