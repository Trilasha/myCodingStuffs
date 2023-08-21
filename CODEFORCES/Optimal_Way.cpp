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


vector<vector<ll>> dp;
ll recur(ll rnd,ll taken,ll k,vector<ll> &v){
    if(rnd==k+1){
        return 0;
    } 
    if(dp[rnd][taken]!=-1) return dp[rnd][taken];
    ll ans=0;
    for(ll i=0;i<v.size();++i){
        if(taken&(1<<i)) continue;
        for(ll j=i+1;j<v.size();++j){
            if(taken&(1<<j)) continue;
                ll newTaken=taken|1<<i;
                newTaken|=1<<j;
                ans=max(ans,rnd*(v[i]&v[j])+ recur(rnd+1,newTaken,k,v));
        }
    }
    return dp[rnd][taken]=ans;
}
void solve(){
    ll n,k;
    cin>>n;
    vector<ll> v(n);
    inpv(v);
    cin>>k;
    dp.resize(n+1,vector<ll>(1<<n,-1));
    cout<<recur(1,0,k,v)<<endl;
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






/*----------------------------------------------------------------------------------------------------------- */
// clear adj and visited vector declared globally after each test case 
// if input newly taken then use 'resize' or else 'assign' (for dp and graphs)
//    BINARY SEARCH ~ 2-PNTS ~ DP 
//    reference for sequence(NT) --> oeis.org
//    log2(x)
//    set.lower_bound(x)
//    for mod division --> a/b use a*inverse(b) (don't divide simply)
//    set<ll> adj[n+1]; --> for adjacency list (to handle erasing of elements)
//    gcd(x,y)=gcd(x-y,y) --->  gcd(x,y,z,...)=gcd(x-y,y,z,...)
//    if nlogn approach gives tle, go for O(n) don't sit idle (for lb/ub replace set with vector)
//    if 100% sure that chk func is correct then try changing the values of lo/hi in the main func (hit and trial)
/*----------------------------------------------------------------------------------------------------------- */



   
//
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007
#define endl "\n"

int32_t main() {

  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tq = 1;
  //cin >> tq;
  while (tq--) {
    int n;
    cin >> n;

    int y;
    cin >> y;
    int mx = 0;
    for (int i = 1; i < n; i++) {
      int x;
      cin >> x;
      mx = max(x, mx);
    }
    cout << max(mx - y + 1, 0LL) << endl;

  }
  return 0;
}



//
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007
#define endl "\n"

int32_t main() {

  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tq = 1;
  //cin >> tq;
  while (tq--) {
    int n, m;
    cin >> n >> m;

    vector<int> outdegree(n + 1);
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      outdegree[b]++;
    }
    int cnt = 0;
    int ans = -1;
    for (int i = 1; i <= n; i++) {
      if (outdegree[i] == 0) {
        cnt++;
        ans = i;
      }
    }

    if (cnt > 1) {
      cout << -1 << endl;
    } else {
      cout << ans << endl;
    }

  }
  return 0;
}



//
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007
#define endl "\n"

int32_t main() {

  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tq = 1;
  //cin >> tq;
  while (tq--) {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int hi = 10000000000000000;
    int lo = 1;
    int ans = 10000000000000000;
    while ((hi - lo) >= 0) {

      int mid = (hi + lo) / 2;

      vector<int> suffixpos(n), suffixneg(n);
      for (int i = n - 1; i >= 0; i--) {

        if (i == (n - 1)) {
          if (mid >= arr[i]) {
            suffixpos[i] = mid - arr[i];
          } else {
            suffixneg[i] = mid - arr[i];
          }
        } else {
          if (mid >= arr[i]) {
            suffixpos[i] = suffixpos[i + 1] + (mid - arr[i]);
            suffixneg[i] = suffixneg[i + 1];
          } else {
            suffixneg[i] = suffixneg[i + 1] + (mid - arr[i]);
            suffixpos[i] = suffixpos[i + 1];
          }

        }
      }


      int prefixpos = 0;
      int prefixneg = 0;
      int diff = 10000000000000000;
      int op = 10000000000000000;
      int l = 10000000000000000;

      int r  = l;
      for (int i = 0; i < n; i++) {

        int pos = prefixpos + suffixpos[i];
        int neg = prefixneg + suffixneg[i];
        // cout << suffixneg[i] << " -- " << suffixpos[i] << endl;
        // cout << pos << " " << neg << endl;
        if (abs(pos + neg) < diff) {
          diff = abs(pos + neg);
          l = pos;
          r = neg;
          op = pos;
        } else if (abs(pos + neg) == diff) {
          op = min(pos, op);
        }

        if ((mid - 1) >= arr[i]) {
          prefixpos += (mid - 1 - arr[i]);
        } else {
          prefixneg += (mid - 1 - arr[i]);
        }

      }

      if ((l + r) > 0) {
        hi = mid - 1;
      } else if ((l + r) < 0) {
        lo = mid + 1;
      } else {
        ans = min(ans, op);
        break;
      }



    }

    cout << ans << endl;

  }
  return 0;
}

