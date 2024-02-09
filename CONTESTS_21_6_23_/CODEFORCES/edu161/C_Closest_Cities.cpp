/*
    When talent doesn't work hard then hardwork beats talent...
    ...hardwork always pays off
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
    vector<ll> v(n);
    inpv(v);
    map<ll,set<ll>> mp;
    for(ll i=0;i<n;++i){
        if(i==0){
            mp[0].insert(1);
        }else if(i==n-1){
            mp[n-1].insert(n-2);    
        }else{
            ll diff=abs(v[i]-v[i-1]);
            ll diff2=abs(v[i]-v[i+1]);
            if(diff==diff2){
                mp[i].insert(i-1);
                mp[i].insert(i+1);
            }else if(diff<diff2){
                mp[i].insert(i-1);
            }else{
                mp[i].insert(i+1);
            }
        }
    }

    vector<ll> pref(n+1),suff(n+1);
    pref[1]=0;
    for(ll i=1;i<n;++i){
        if(mp[i-1].count(i)){
            pref[i+1]=pref[i]+1;
        }else{
            pref[i+1]=pref[i]+abs(v[i]-v[i-1]);
        }
    }
    suff[n]=0;
    for(ll i=n-2;i>=0;--i){
        if(mp[i+1].count(i)){
            suff[i+1]=suff[i+2]+1;
        }else{
            suff[i+1]=suff[i+2]+abs(v[i]-v[i+1]);
        }
    }

    ll q;
    cin>>q;
    fr(i,q){
        ll x,y;
        cin>>x>>y;
        if(mp[x-1].count(y-1)){
            cout<<1<<endl;
            continue;
        }
        if(x<y){
            ll ans=pref[y]-pref[x];
            cout<<ans<<endl;
        }else{
            ll ans=suff[y]-suff[x];
            cout<<ans<<endl;
        }
    }
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

