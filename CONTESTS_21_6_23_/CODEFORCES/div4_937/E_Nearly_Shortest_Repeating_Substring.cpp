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
    string s;
    cin>>s;
    ll ans=n;
    vector<ll> vec;
    for(ll i=1;i*i<=n;++i){
        if(n%i==0){
            vec.pb(i);
            if(i!=n/i){
                vec.pb(n/i);
            }
        }
    }   

    function<bool(ll)> check=[&](ll mid){
        if(n%mid) return false;
        vector<vector<ll>> mp(mid+1,vector<ll>(27));
        for(ll i=0;i<n;++i){
            mp[i%mid][s[i]-'a']++;
        }
        ll ok=0;
        for(ll i=0;i<mid;++i){
            multiset<ll> st;
            ll mx=0;
            for(ll j=0;j<26;++j){
                if(mp[i][j]>0)
                    st.insert(mp[i][j]);
                mx=max(mx,mp[i][j]);
            }
            st.erase(st.find(mx));
            if(st.size()>1){
                return false;
            }
            if(!st.empty()){
                ll x=*st.begin();
                if(x>1){
                    return false;
                }
                ok++;
            }
        }
        return (ok<=1);
    };
    for(ll i=0;i<vec.size();++i){
        if(check(vec[i])){
            ans=min(ans,vec[i]);
        }
    }
    // cout<<check(2)<<endl;
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

