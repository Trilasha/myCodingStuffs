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
    ll n,k;
    cin>>n>>k;
    vector<vector<ll>> v(k);
    string s;
    cin>>s;
    for(ll i=0;i<n;++i){
        v[(i+1)%k].pb(s[i]-'0');
    }
    ll ans=INT_MAX;
    //all zero
    ll ok=0;
    ll chk=0;
    for(ll i=0;i<k;++i){
        // ll sz=v[i].size();
        ll zero=0,one=0;
        if(v[i].size()==0)continue;
        for(ll j=0;j<v[i].size();++j){
            if(v[i][j]==0)zero++;
            else one++;
        }
        if(one==1 && zero==0){
            chk=-1;
            continue;
        }
        if(one%2){
            ok+=(one/2);
            ok+=2;
        }else{
            ok+=(one/2);
        }
    }
    if(chk!=-1)ans=ok;
    chk=0;
    ok=0;
    for(ll i=0;i<k;++i){
        // ll sz=v[i].size();
        ll zero=0,one=0;
        if(v[i].size()==0)continue;
        for(ll j=0;j<v[i].size();++j){
            if(v[i][j]==0)zero++;
            else one++;
        }
        if(one==0){
            chk=-1;
        }else{
            ok+=zero;
        }
    }
    if(chk!=-1){
        ans=min(ok,ans);
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

