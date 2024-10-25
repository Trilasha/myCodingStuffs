/*
    "When you are in darkness, listen to the whispers of your heart
    but when you are in light, listen to the thunder of your brain."
    
*/

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
// insead of bpow use shift operators when b=2 to avoid tle 
// do not perform more than one optimal choice/ops in a single step/loop otherwise break your head with WA
/*----------------------------------------------------------------------------------------------------------- */





void solve(){
    ll n,x;
    cin>>n>>x;
    ll mx=n;
    for(ll i=59;i>=0;--i){
        ll bit=(1LL<<i);
        if(x&bit && !(n&bit)){
            // line
            cout<<-1<<endl; 
            return;
        }else if(!(x&bit) && (n&bit)){
            bit=(1LL<<(i+1));
            ll nxt=(n+1)/bit;
            if((n+1)%bit!=0)
                mx=max(mx,bit*(nxt+1));
            else 
                mx=max(mx,bit*nxt);
        }
    }
    // cout<<mx<<endl;
    ll ans=0;
    for(ll i=60;i>=0;--i){
        ll bit=(1LL<<i);
        if(x&bit){
            ll diff=mx-n;
            if(diff>=bit || !(n&bit) || !(mx&bit)){
                cout<<-1<<endl;
                return;
            }
            ans+=bit;
        }
    }
    cout<<((ans==x)?mx:-1)<<endl;
 
}


int main(){

fast_io;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

ll q=1;
cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}

