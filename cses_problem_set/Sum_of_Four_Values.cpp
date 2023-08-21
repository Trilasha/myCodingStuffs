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
  ll n,x;
  cin>>n>>x;
  vector<ll> v(n);
  inpv(v);
  if(n<=3){
    cout<<"IMPOSSIBLE\n";
    return;
  }

  map<ll,set<ll>> mp;
  fr(i,n){
    mp[v[i]].insert(i+1);
  }
  sort(all(v));
  ll i=0,j=n-1,k=1,l=n-2,ok=0;
  while(i<j){
    ll sum=v[i]+v[j];
    if(sum>=x)j--;
    else{
        k=i+1;l=j-1;
        while(k<l){
            ll sum2=v[k]+v[l];
            if(sum2>=x)l--;
            else{
            if(sum+sum2==x){
                ok=1;
                break;
            }
            else k++;
            }
        }
        if(ok)break;
        i++;
    }
  }
  if(!ok){
    cout<<"IMPOSSIBLE\n";
    return;
  }
  ll a=v[i],b=v[j],c=v[k],d=v[l];
  cout<<*mp[a].begin()<<" ";
  mp[a].erase(mp[v[i]].begin());
  cout<<*mp[b].begin()<<" ";
  mp[b].erase(mp[v[j]].begin());
  cout<<*mp[c].begin()<<" ";
  mp[c].erase(mp[v[k]].begin());
  cout<<*mp[d].begin()<<endl;

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
/*----------------------------------------------------------------------------------------------------------- */



   
