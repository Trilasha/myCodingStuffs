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
    do{
        ll cal=0;
        ll mx=0;
        for(ll i=0;i<n;++i){
            cal+=(v[i]*(i+1));
            mx=max(mx,v[i]*(i+1));
        }
        cal-=mx;
        if(cal==303){
            printv(v);
        }
    }while(next_permutation(all(v)));
*/
void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    iota(all(v),1);

    ll ans=0;
    for(ll i=0;i<n;++i){
        ll cal=0;ll mx=0;
        for(ll j=0;j<i;++j){
            cal+=(v[j]*(j+1));
            mx=max(mx,v[j]*(j+1));
        }
        ll come=n;
        for(ll j=i;j<n;++j){
            cal+=(v[j]*come);
            mx=max(mx,v[j]*come);
            come--;
        }
        cal-=mx;
        ans=max(ans,cal);
    }
    cout<<ans<<endl;
    
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





   
