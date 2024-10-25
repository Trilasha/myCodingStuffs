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
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> v(n);
    inpv(v);
    vector<ll> a(m),b(k);
    inpv(a);inpv(b);
    sort(all(a));
    sort(all(b));
    sort(all(v));
    ll mx=0;ll st=0;
    map<ll,ll> mp;
    vector<ll> d;
    ll sec=0;
    for(ll i=0;i<n-1;++i){
        ll diff=v[i+1]-v[i];
        mp[diff]++;
        d.pb(diff);
        if(diff>mx){
            //sec=mx;
            mx=diff;
            st=v[i];
        }
    }
    if(mp[mx]>1){
        cout<<mx<<endl;
        return;
    }
    sec=0;
    sort(all(d));
    d.pop_back();
    if(!d.empty())
    sec=d.back();
    ll ans=mx;
    // cout<<st<<" "<<mx<<" "<<sec<<endl;
    for(ll i=0;i<m;++i){
        ll fnd=(st+st+mx)/2;
        ll src=fnd-a[i];
        ll ind=lb(all(b),src)-b.begin();
        ll ch=mx;
        // cout<<ind<<" "<<b[ind]<<endl;
        if(ind!=k){
            ch=min(ch,max(a[i]+b[ind]-st,st+mx-a[i]-b[ind]));
        }
        if((ind+1)<k){
            ch=min(ch,max(a[i]+b[ind+1]-st,st+mx-a[i]-b[ind+1]));
        }
        if((ind-1)>=0){
            ch=min(ch,max(a[i]+b[ind-1]-st,st+mx-a[i]-b[ind-1]));
        }
        // cout<<ch<<endl;
        ans=min(ans,ch);
    }
    //cout<<ans<<" "<<sec<<endl;
    if(ans<sec)ans=sec;
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
