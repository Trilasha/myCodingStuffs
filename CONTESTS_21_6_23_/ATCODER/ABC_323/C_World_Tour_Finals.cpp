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
    ll n,m;
    cin>>n>>m;
    vector<ll> v(m);
    inpv(v);
    vector<ll> score;
    vector<vector<pll>> left(n);
    fr(i,n){
        ll scoreS=i+1;
        fr(j,m){
            char ch;
            cin>>ch;
            if(ch=='o'){
                scoreS+=v[j];
            }else{
                left[i].pb({v[j],j});
            }
        }
        sort(all(left[i]),greater<pll>());
        score.pb(scoreS);
    }
    vector<ll> ans;
    ll mx=*max_element(all(score));
    // cout<<mx<<endl;
    fr(i,n){
        ll cnt=0;
        ll curr=score[i];
        for(ll j=0;j<left[i].size();++j){
            if(curr>=mx)break;
            cnt++;
            curr+=v[left[i][j].ss];
        }
        ans.pb(cnt);
    }
    for(auto &i:ans){
        cout<<i<<endl;
    }
}


int main(){

fast_io;

ll q=1;
// cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}

