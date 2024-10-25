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
    ll n;
    cin>>n;
    string v;
    cin>>v;
    ll ans=0;
    ll ok=0;
    for(ll i=0;i<n;++i){
        ll len=n-i;
        if(len<=2)break;
        char a=v[i];
        char b=v[i+1];
        char c=v[i+2];
        if(len==3){
            if(a!=b || b!=c || c!=a){
                ans++;
            }else if(a==b && b==c)ok=1;
        }else if(len==4){
            char d=v[i+3];
            if(a!=b || b!=c || c!=a){
                ans++;
            }else if(a==b && b==c)ok=1;
            if(b==a && a==d && d==b){
                i++;
            }
        }else{
            char d=v[i+3];
            char e=v[i+4];
            if(a!=b || b!=c || c!=a){
                ans++;
            }else if(a==b && b==c)ok=1;
            if(b==a && a==d && d==b){
                i++;
            }
            if(b==a && c==b && a==d && d==e && e==c){
                i++;
            }
        }
    }
    cout<<ans+ok<<endl;
 
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

