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
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    inpv(v);
    ll lo=0, hi=n;
    ll ans=0;
    sort(all(v));

    function<bool(ll)> check=[&](ll H){
        ll cnt=0;
        ll ks=0;
        ll ava=0;
        ll tot=0;
        for(ll i=0;i<n;++i){
            if(v[i]%k && v[i]<H)ava++;
        }
        vector<ll> temp;
        for(ll i=0;i<n;++i){
            if(v[i]>H){
                cnt++;
                ll val=v[i];
                while(val>H){
                    ll rem=val%k;
                    ll dv=val/k;
                    if(rem==0 && dv>=H && ava>0){
                        ks++;
                        ava--;
                        val=dv;
                    }else break;
                }
                // if(val%k && val!=v[i]) ava++;
            }else{
                temp.pb(v[i]);
            }
        }
        // ks=min(ava,ks);
        sort(all(temp),greater<ll>());
        for(ll i=0;i<temp.size();++i){
            ll use=0;
            if(temp[i]<H && ks>0){
                temp[i]*=k;
                ks--;
                use++;
            }
            if(temp[i]>=H){
                cnt++;
            }else{
                ks+=use;
            }
            if(ks==0)break;
        }
        return (cnt>=H);
    };
    while(lo<=hi){
        ll H=(lo+hi)/2;
        if(check(H)){
            ans=H;
            lo=H+1;
        }else{
            hi=H-1;
        }
    }
    // cout<<check(4)<<endl;
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

