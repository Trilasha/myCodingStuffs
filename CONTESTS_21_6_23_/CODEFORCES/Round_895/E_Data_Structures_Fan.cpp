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
    vector<ll> v(n);
    inpv(v);
    string s;
    cin>>s;
    ll ones=0,zeroes=0;
    for(ll i=0;i<n;++i){
        if(s[i]=='1')ones^=v[i];
        else zeroes^=v[i];
    }
    vector<ll> pref(n+1);
    pref[1]=v[0];
    for(ll i=1;i<n;++i){
        pref[i+1]=pref[i]^v[i];
    }

    ll qq;
    cin>>qq;
    for(ll i=0;i<qq;++i){
        ll type;
        cin>>type;
        if(type==2){
            ll val;
            cin>>val;
            cout<<((val==1)?ones:zeroes)<<" ";
        }else{
            ll l,r;
            cin>>l>>r;
            ones^=(pref[r]^pref[l-1]);
            zeroes^=(pref[r]^pref[l-1]);
        }
    }
    cout<<endl;
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

