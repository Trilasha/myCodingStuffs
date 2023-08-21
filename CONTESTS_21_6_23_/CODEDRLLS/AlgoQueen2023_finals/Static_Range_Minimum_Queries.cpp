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


// https://cp-algorithms.com/sequences/rmq.html


//method 1 : square root decomposition
//preprocessing -> O(N)
//query         -> O(root(N))
//update        -> O(1)


/*
1. It is fact that Segment Tree is having a better time complexity than Square Root Decomposition (SRD) method.
2. Segment Tree needs larger space (N)  to represent it than SRD method (sqrt(N)).
3. Segment Tree is easy to understand (more intuitive in nature) , but a little bit trickier and time consuming to implement.
4. On the other Hand being an iterative method, Square Root Decomposition, is easier to implement, but little bit difficult to understand.
5. And finally both are capable enough to do all possible query operations (query + update).
*/


//TLE
const int N = 2e5 + 5;
const int K = 450;


void solve() {
	ll n;
    cin>>n;
    vector<ll> v(n),bucket(N);
    inpv(v);

    ll root=sqrt(n);
    for(ll i=0;i<n;++i){
        if(i%root==0){
            bucket[i/root]=v[i];
        }else{
            bucket[i/root]=min(bucket[i/root],v[i]);
        }
    }
    ll q;
    cin>>q;

    fr(i,q){
        ll l,r;
        cin>>l>>r;
        l--;r--;
        ll ans=INT_MAX;
        for(ll j=l;j<=r;++j){
            if(j%root==0 && j+root-1<=r){
                ans=min(ans,bucket[j/root]);
                j+=root-1;
            }else{
                ans=min(ans,v[j]);
            }
        }
        cout<<ans<<endl;
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






   
