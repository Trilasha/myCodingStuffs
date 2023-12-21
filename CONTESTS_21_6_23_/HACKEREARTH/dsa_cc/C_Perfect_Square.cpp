/* Trilasha Mazumder */


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







void solve(){
    ll n;
    cin>>n;
    vector<string> st;
    fr(i,n){
        string s;
        cin>>s;
        st.pb(s);
    }
    vector<vector<char>> v(n,vector<char>(n)),copy;
    fr(i,n){
        fr(j,n){
            v[i][j]=st[i][j];
        }
    }
    ll cnt=0;
    for(ll i=0;i<n;++i){
        vector<char> temp;
        for(ll j=0;j<n;++j){
            temp.pb(v[j][i]);
        }
        reverse(all(temp));
        copy.pb(temp);
    }
    for(ll i=0;i<n;++i){
        for(ll j=0;j<n;++j){
            cout<<copy[i][j]<<" ";
        }cout<<endl;
    }
    for(ll i=0;i<n;++i){
        for(ll j=0;j<n;++j){
            if(v[i][j]!=copy[i][j]){
                cnt+=abs(v[i][j]-copy[i][j]);
            }
        }
    }
    cout<<cnt<<endl;
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

