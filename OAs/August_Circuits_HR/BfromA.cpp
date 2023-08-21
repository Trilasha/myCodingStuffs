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
#define sp(x)                 fixed<<setprecision(x)
#define md                    998244353
#define modval                1000000007
#define PI                    3.141592653589793238
#define bpl(n)                __builtin_popcountll(n);
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
// define endl                " \n"
 




void solve(){
    ll n,m;
    cin>>n>>m;
    string a,b;
    cin>>a>>b;
    vector<ll> cnta(26),cntb(26);
    for(auto &i:b){
        cntb[i-'a']++;
    }
    for(auto &i:a){
        cnta[i-'a']++;
    }
    // cout<<"---"<<endl;
    ll ans=n;
    for(char ch='a';ch<='z';++ch){
        if(!cntb[ch-'a'])continue;
        if(cnta[ch-'a']<cntb[ch-'a']){
            cout<<0<<endl;
            return;
        }
        ans=min(ans,cnta[ch-'a']/cntb[ch-'a']);
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
