/* ...  risen_ash  ... */

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
// define endl                " \n"
/*----------------------------------------------------------------------------------------------------------- */






void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    inpv(v);
    vector<ll> pref(n);
    pref[0]=0;
    ll sum=0;
    for(ll i=1;i<n;++i){

        if(i%2==0){
        pref[i]=v[i]-v[i-1]+sum;
        sum+=v[i]-v[i-1];
        }
        else{
            pref[i]=sum;
        }
    }

    //printv(pref);

    ll q;
    cin>>q;
    while(q--){
        ll l,r;
        cin>>l>>r;
        ll upper=0;

        ll up_lb=lower_bound(all(v),r)-v.begin();
        if(up_lb==n || up_lb%2!=0){
            if(up_lb==n)up_lb--;
            upper=pref[up_lb-1];
        }else{
            upper=pref[up_lb]-(v[up_lb]-r);
        }
        //cout<<upper<<endl;

        ll low_lb=lower_bound(all(v),l)-v.begin();
        ll to_minus=0;

        if(low_lb>0){
            to_minus=pref[low_lb-1];
            if((low_lb-1)%2!=0){
                to_minus+=(l-v[low_lb-1]);
            }
        }
        //cout<<upper<<" "<<to_minus<<endl;
        cout<<upper-to_minus<<endl;

    }
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











/*--------------------------------------------------------------------------------------------------------- 
   reference for sequence(NT) --> oeis.org
   log2(x)
   set.lower_bound(x)
   for mod division --> a/b use a*inverse(b) (don't divide simply)
   set<ll> adj[n+1]; --> for adjacency list (to handle erasing of elements)
   gcd(x,y)=gcd(x-y,y) --->  gcd(x,y,z,...)=gcd(x-y,y,z,...)
   --------------------------------------------------------------------------------------------------------- */