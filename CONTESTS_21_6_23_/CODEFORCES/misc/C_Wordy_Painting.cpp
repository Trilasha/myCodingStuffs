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
    ll n,q;
    cin>>n>>q;
    map<pair<pll,char>,ll> mp;
    map<pll,ll> val;
    map<pll,stack<ll>> st;
    fr(i,q){
        ll type;
        cin>>type;
        if(type==0){
            char ch;
            ll x,y;
            cin>>ch>>x>>y;
            mp[{ {x,y},ch }]++;
            val[{x,y}]++;
            st[{x,y}].push(ch);
        }else if(type==1){
            ll x,y;
            cin>>x>>y;
            if(val[{x,y}]){
                val[{x,y}]--;
                char c=st[{x,y}].top();
                st[{x,y}].pop();
                mp[{ {x,y},c }]--;
            }
        }else{
            char ch;
            ll x,y;
            cin>>ch>>x>>y;
            ll tot=val[{x,y}];
            ll mx=(tot/2)+1;
            ll ok=0;
            // cout<<mx<<endl;
            for(char c='a';c<='z';++c){
                if(mp[{{x,y},c}]>=mx){
                    ok=1;
                    break;
                }
            }
            cout<<((ok)?"yes":"no")<<endl;
        }
    }
 
}


int main(){

fast_io;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

ll q=1;
// cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}

