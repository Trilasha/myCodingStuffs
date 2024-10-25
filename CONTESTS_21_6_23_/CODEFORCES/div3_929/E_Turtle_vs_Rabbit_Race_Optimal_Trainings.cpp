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


// MAR GYA BRAIN 



void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    inpv(v);
    vector<ll> pref(n+2);
    pref[1]=v[0];
    for(ll i=2;i<=n;++i){
        pref[i]=pref[i-1]+v[i-1];
    }
    ll q;
    cin>>q;
    function<ll(ll,ll,ll)> check=[&](ll left,ll val,ll take){
        ll sum=pref[left+take]-pref[left-1];
        ll ava=(val*(val+1))/2;
        if(sum<=val){
            ll rem=val-sum;
            ll sub=rem*(rem+1)/2;
            return (ava-sub);
        }
        ll rem=sum-val;
        rem--;
        ll sub=(rem*(rem+1))/2;
        return (ava-sub);
    };
    while(q--){
        ll l,u;
        cin>>l>>u;
        ll lo=0,hi=n-l;
        ll ans=0;
        while(lo<=hi){
            ll mid=(lo+hi)/2;
            // cout<<mid<<endl;
            ll x=check(l,u,mid);
            ll y=check(l,u,mid+1);
            // cout<<mid<<" "<<x<<" "<<y<<"-->"<<lo<<" "<<hi<<endl;
            if(x>=y){
                ans=mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        // cout<<ans<<endl;
        // cout<<check(l,u,1)<<" "<<check(l,u,2)<<endl;
        cout<<l+ans<<" ";
    }
    cout<<endl;
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

