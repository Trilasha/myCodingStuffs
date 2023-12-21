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





const ll N=1e6+10;

vector<ll> prime(N),vec(N);

void func(){
	for (ll i = 1; i <=N; i++)
		vec[i] = i;
	for (ll i = 2; i <=N; i++) {
		if (prime[i] == 0)
			for (ll j = i; j <=N; j += i) {
				prime[j] = 1;
				while (vec[j] % (i * i) == 0)
				    vec[j] /= (i * i);
			}
	}
}


void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    inpv(v);
	map<ll,ll> mp;
	for (ll i = 0; i < n; i++) {
        cout<<vec[[i]]<<" ";
		mp[vec[v[i]]]++;
	}
	ll ans = 0;
	for (auto i : mp) {
        ll val=i.second;
		ans += ((val- 1) * val) / 2;
	}
	cout<<ans<<endl;
}


int main(){

fast_io;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

func();
ll q=1;
// cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}

