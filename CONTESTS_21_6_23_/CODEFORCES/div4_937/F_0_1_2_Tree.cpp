/*
    Trilasha Mazumder
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





void solve(){
    ll a,b,c;
    cin>>a>>b>>c;
    ll ans=0;
    if(a==0 && b==0){
        if(c<=1){
            cout<<0<<endl;
            return;
        }
        cout<<-1<<endl;
        return;
    }
    if(a==0){
        if(c!=1){
            cout<<-1<<endl;
            return;
        }
        cout<<b<<endl;
        return;
    }
    ll p=log2(a);
    ans=p+1LL;
    ll nextp=(1LL<<(p));
    ll rem=nextp-(a-(nextp-1LL));
    ll leaf=rem;
    ll val=a-(nextp-1LL);
    leaf+=2*(val);
    if(c!=leaf){
        cout<<-1<<endl;
        return;
    }
    if(b<=rem){
        cout<<ans<<endl;
        return;
    }
    b-=rem;
    ans+=(b+leaf-1)/leaf;
    cout<<ans<<endl;



 
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

