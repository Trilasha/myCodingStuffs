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
    ll ori=0;
    map<ll,ll> mp,cnt,out;
    for(auto &i:v){
        for(ll j=0;j<=31;++j){
            if(i&(1LL<<j)){
                out[j]++;
                ori|=(1LL<<j);
            }
        }
    }
    ll len=n;
    ll j=0;
    ll curr=0;
    ll oth=ori;
    for(ll i=0;i<n;++i){
        curr|=v[i];
        for(ll x=0;x<=31;++x){
            if(v[i]&(1LL<<x)){
                mp[x]++;
                if(out[x]>0){
                    out[x]--;
                    if(out[x]==0){
                        oth-=(1LL<<x);
                    }
                }
            }
        }
        while(j<i && curr==ori){
            ll ok=0;
            for(ll k=0;k<=31;++k){
                if(v[j]&(1LL<<k)){
                    if((mp[k]-1)<=0){
                        ok=1;
                        break;
                    }
                }
            }
            if(ok)break;
            for(ll k=0;k<=31;++k){
                if(v[j]&(1LL<<k)){
                   mp[k]--;
                   if(out[k]==0){
                        oth+=(1LL<<k);
                   }
                   out[k]++;
                }
            }
            j++;
        }
        ll x=i-j+1;
        if(curr==ori && oth==ori && x<=len){
            len=x;
            cnt[len]++;
        }
    }
    if(len==n){
        cout<<-1<<endl;
        return;
    }
    cout<<len<<" "<<cnt[len]<<endl;
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

