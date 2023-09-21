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




/*
    n=7 x=2, y=3

    1 2 3 4 5 6 7
    
    x -> 2+4+6
    y -> 3+6
    score = 12-9 = 3

    x -> 7+6+5
    y -> 1+2
    no common indices -> 1 (6th index)
    x-> 7+6
    y->1

    n*(n+1)/2

    1 2 3 4 5 6 7 
    7*(7+1)/2 - 5*(5+1)/2
*/

ll lcm(ll a,ll b){
    return (a*b)/__gcd(a,b);
}

void solve(){
    ll n,x,y;
    cin>>n>>x>>y;
    ll sum=n*(n+1)/2;
    ll a=n/x;
    ll b=n/y;
    ll rem=n/lcm(x,y);
    a-=rem;
    a=(n-a);
    b-=rem;
    ll add=sum-(a*(a+1)/2);
    ll sub=b*(b+1)/2;
    cout<<add-sub<<endl;

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

