/** Let it hurt then let it go.. */

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
#define endl                " \n"
/*----------------------------------------------------------------------------------------------------------- */
// insead of bpow use shift operators when b=2 to avoid tle 
// do not perform more than one optimal choice/ops in a single step/loop otherwise break your head with WA
/*----------------------------------------------------------------------------------------------------------- */





void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    inpv(a);
    ll m;
    cin>>m;
    vector<string> s(m);
    fr(i,m){
        cin>>s[i];
    }
    vector<ll> mark(m);
    for(ll j=0;j<m;++j){
        string str=s[j];
        map<ll,char> mp1;
        if(str.size()!=n){
            mark[j]=1;
            continue;
        }
        for(ll i=0;i<n;++i){
            if(!mp1.count(a[i])){
                mp1[a[i]]=str[i];
            }else if(mp1[a[i]]!=str[i]){
                mark[j]=1;
                break;
            }
        }
    }
    for(ll j=0;j<m;++j){
        string str=s[j];
        if(str.size()!=n){
            mark[j]=1;
            continue;
        }
        map<char,ll> mp1;
        for(ll i=0;i<n;++i){
            if(!mp1.count(str[i])){
                mp1[str[i]]=a[i];
            }else if(mp1[str[i]]!=a[i]){
                mark[j]=1;
                break;
            }
        }
    }
    for(ll i=0;i<m;++i){
        if(mark[i]){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }
 
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

