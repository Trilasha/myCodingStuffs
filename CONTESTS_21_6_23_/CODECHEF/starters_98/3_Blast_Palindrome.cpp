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
    ll n;
    cin>>n;
    string s;
    cin>>s;
    if(n<=3){
        if(n==1){
            cout<<"YES"<<endl;
            return;
        }
        if(n==2 && s[0]==s[1]){
            cout<<"YES"<<endl;
            return;
        }
        if(n==3 && s[0]==s[2]){
            cout<<"YES"<<endl;
            return;
        }

        cout<<"NO"<<endl;
        return;
    }

    ll val=n%3;
    if(val==1){
        cout<<"YES"<<endl;
        return;
    }
   ll ok=0;
   for(char ch='a';ch<='z';++ch){
     ll ind1=INT_MAX;
     ll ind2=INT_MIN;
     for(ll i=0;i<n;++i){
        if(i%3==0 && s[i]==ch){
            ind1=i;
            break;
        }
     }
        for(ll i=n-1;i>=0;--i){
            ll req=n-1-i;
            if(req%3==0 && s[i]==ch){
                ind2=i;
                break;
            }
        }
        if(ind1<ind2){
            ok=1;
            break;
        }
   }

   cout<<((ok)?"YES":"NO")<<endl;
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
//    if 100% sure that chk func is correct then try changing the values of lo/hi in the main func (hit and trial)
/*----------------------------------------------------------------------------------------------------------- */



   
