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
// define endl                " \n"
/*----------------------------------------------------------------------------------------------------------- */






void solve(){
    ll n,k,g;
    cin>>n>>k>>g;

    ll tot=k*g;

    ll gby2=(g+2-1)/2;
    ll more=gby2-1;

    if(more==0){
        cout<<0<<endl;
        return;
    }
    
    ll moreAddCnt=tot/more;

    if(moreAddCnt<=n && tot%more==0){
        ll ans=((moreAddCnt)*more);
        cout<<ans<<endl;
        return;
        //line
    }
    //cout<<tot<<endl;
    // line

    if(moreAddCnt>n){
    ll var=(n-1)*more;

    //cout<<var<<endl;
    ll x=(k*g)-(var);
    ll rem=x%g;

    if(rem<gby2){
        ll ans=var+rem;
        cout<<ans<<endl;
    }else{
        var-=(g-rem);
        cout<<var<<endl;
    }
    return;
    }

    else{
        //cout<<more<<endl;
        ll var=(moreAddCnt)*more;
        //one rem
        ll x=(k*g)-(var);
        ll rem=x%g;
        if(moreAddCnt<n){
            if(rem<gby2){
            ll ans=var+rem;
            cout<<ans<<endl;
            }else{
                var-=(g-rem);
                cout<<var<<endl;
            }
            return;
        }

        var-=more;
        x=(k*g)-(var);
        rem=x%g;
        if(rem<gby2){
            ll ans=var+rem;
            cout<<ans<<endl;
        }else{
            var-=(g-rem);
            cout<<var<<endl;
        }
    }

    //line
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











/*--------------------------------------------------------------------------------------------------------- 
   reference for sequence(NT) --> oeis.org
   log2(x)
   set.lower_bound(x)
   for mod division --> a/b use a*inverse(b) (don't divide simply)
   set<ll> adj[n+1]; --> for adjacency list (to handle erasing of elements)
   gcd(x,y)=gcd(x-y,y) --->  gcd(x,y,z,...)=gcd(x-y,y,z,...)
   a+b=2⋅(a&b)+a⊕b
   a⊕b=¬(a&b)&(a∣b)
   --------------------------------------------------------------------------------------------------------- */