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



bool cmp(pair<ll,pair<ll,ll>> &a,pair<ll,pair<ll,ll>> &b){
  if(a.ff==b.ff){
    if(a.ss.ff==b.ss.ff){
      return a.ss.ss<b.ss.ss;
    }
    return a.ss.ff<b.ss.ff;
  }
  return a.ff>b.ff;
}

void solve(){
  ll n,m,tot;
  cin>>n>>m>>tot;
  vector<vector<ll>> v(n,vector<ll>(m));
  fr(i,n){
    fr(j,m){
      cin>>v[i][j];
    }
  }

  vector<pair<ll,pair<ll,ll>>> vp;
  
  for(ll i=0;i<n;++i){
    sort(all(v[i]));
    ll score=0,penalty=0;ll time=0;
    for(ll j=0;j<m;++j){
        time+=v[i][j];
        if(time>tot) break;
        score+=1;
        penalty+=time;
    }
    vp.pb({score,{penalty,i+1}});
  }

  sort(all(vp),cmp);

  ll pos=0;
  for(auto &x:vp){
    pos++;
    if(x.ss.ss==1){
        cout<<pos<<endl;
        return;
    }
  }
}


int main(){

fast_io;

ll q=1;
cin>>q;
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
/*----------------------------------------------------------------------------------------------------------- */



   
