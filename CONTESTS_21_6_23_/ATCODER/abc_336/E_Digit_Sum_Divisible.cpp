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





ll dp[16][2][2][132][132];
ll check[16][2][2][132][132];
ll cur=0;

ll count(ll index,ll larger,ll smaller,ll left,ll mod,ll sum, string L,string R){
        if (index == L.length()) {
			if (left == 0 && mod == 0) {
				return 1;
			}
			return 0;
		}
		if((L.length() - index) * 9 < left){
			return 0;
		}
		if (check[index][larger][smaller][left][mod] == cur) {
			return dp[index][larger][smaller][left][mod];
		}
		check[index][larger][smaller][left][mod] = cur;
		ll x = L[index] - '0';
		ll y = R[index] - '0';
		ll result = 0;
		for (ll i = 0; i < 10 && i <= left; i++) {
		
			if (x > i && larger == 0) {
				continue;
			}
			if (y < i && smaller == 0) {
				continue;
			}
			ll nxtLarger = larger;
			ll nxtSmaller = smaller;
			if (x < i) {
				nxtLarger = 1;
			}
			if (y > i) {
				nxtSmaller = 1;
			}
			ll nxtMod = (mod * 10 + i) % sum;
			result += count(index + 1, nxtLarger, nxtSmaller, left - i, nxtMod,
					sum, L, R);
		}
		return dp[index][larger][smaller][left][mod] = result;
}
void solve(){
    ll n;
    cin>>n;
    string L=to_string(0);
    string R=to_string(n);
    while (L.length() < R.length()) {
        L = "0" + L;
    }
    ll ans = 0;
    for (ll j = 1; j <= 131; j++) {
        cur = cur + 1;
        ans += count(0, 0, 0, j, 0, j, L, R);
    }
    cout<<ans<<endl;
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

