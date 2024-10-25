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
    ll r,c,n;
    cin>>r>>c>>n;
    string s;
    cin>>s;
    vector<vector<char>> v(r,vector<char>(c));
    fr(i,r){
        string t;
        cin>>t;
        fr(j,c){
            v[i][j]=t[j];
        }
    }
    ll ans=0;
    set<pll> st;
    function<pll(ll,ll)> check=[&](ll x,ll y){
        pll p={-1,-1};
        ll ok=0;
        for(auto &i:s){
            if(i=='L')y--;
            if(i=='R')y++;
            if(i=='U')x--;
            if(i=='D')x++;
            if(x<0||x>=r||y<0||y>=c || v[x][y]=='#'){
                ok=1;
                break;
            }
        }
        if(ok) return p;
        p={x,y};
        return p;
    };
    fr(i,r){
        fr(j,c){
            if(v[i][j]=='.'){
                pll pp=check(i,j);
                pll d={-1,-1};
                if(pp!=d){
                    st.insert(pp);
                }
            }
        }
    }
    cout<<st.size()<<endl;
 
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

