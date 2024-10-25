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
    ll n,b,x;
    cin>>n>>b>>x;
    vector<ll> v(n);
    inpv(v);
    ll lo=1;
    ll hi=*max_element(all(v));
    ll ans=0;

    function<ll(ll)> func=[&](ll squad){
        ll val=-((squad-1)*x);
        for(ll i=0;i<n;++i){
            ll div=v[i]/squad;
            ll rem=v[i]%squad;
            if(rem==0){
                val+=div*div*b*((squad*(squad-1))/2);
            }else{
                ll a1=squad-rem;
                val+=div*div*b*((a1*(a1-1))/2);
                val+=(div+1)*(div+1)*b*((rem*(rem-1))/2);
                val+=rem*(div+1)*a1*div*b;
            }
        }
        return val;
    };
    while(lo<=hi){
        ll mid=(lo+hi)/2;
        ll x=func(mid);
        ll y=func(mid+1);
        ans=max(ans,x);
        ans=max(ans,y);
        if(x<=y){
            lo=mid+1;
        }else{
            hi=mid-1;
        }
    }
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

