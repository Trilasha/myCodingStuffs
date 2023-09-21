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
    ll n,l,r;
    cin>>n>>l>>r;
    ll ans=0;

    if(n%2==0){
        if(l>n/2){
            //even
            l-=n/2;
            ll half=(n/2);
            ll rem=(half+1)/2;
            if(l>rem){
                l=l-rem;
                ans=(4+((l-1)*4));
            }else{
                ans=(2+((l-1)*4));
            }
        }else{
            //odd
            ll half=(n/2);
            ll rem=(half+1)/2;
            if(l>rem){
                l=l-rem;
                ans=(3+((l-1)*4));
            }else{
                ans=(1+((l-1)*4));
            }
        }
    }else{
        if((l>((n+1)/2))){
            l-=(n+1)/2;
            ll half=n/2;
            ll rem=(half+1)/2;
            if(l>rem){
                l=l-rem;
                ans=(4+((l-1)*4));
            }else{
                ans=(2+((l-1)*4));
            }
        }else{
            ll half=(n+1)/2;
            ll rem=(half+1)/2;
            if(l>rem){
                l=l-rem;
                ans=(3+((l-1)*4));
            }else{
                ans=(1+((l-1)*4));
            }
        }
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

