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
    k--;
    vector<ll> v(n);
    inpv(v);
    ll ans=0;
    ll mx=0;
    for(ll i=0;i<k;++i){
        mx=max(mx,v[i]);
    }
    if(mx>0 && mx<v[k])ans++;
    mx=v[k];
    for(ll i=k+1;i<n;++i){
        mx=max(mx,v[i]);
        if(mx!=v[k])break;
        ans++;
    }
    ll ori=k;

    ll ind=k;
    for(ll i=0;i<k;++i){
        if(v[i]>v[k]){
            ind=i;
            break;
        }
    }
    // if(ind==k)ans=max(ans,k);
    swap(v[k],v[ind]);
    k=ind;
    ll cnt=0; 
    mx=0;
    for(ll i=0;i<k;++i){
        mx=max(mx,v[i]);
    }
    if(mx>0 && mx<v[k])cnt++;   
    mx=v[k];
    for(ll i=k+1;i<n;++i){
        mx=max(mx,v[i]);
        if(mx!=v[k])break;
        cnt++;
    }
    // cout<<ans<<" "<<cnt<<endl;
    // line
    ans=max(ans,cnt);
    ans=max(ans,k-1);


    swap(v[ori],v[k]);
    cnt=0;
    swap(v[ori],v[0]);
    k=0;
    // if(mx>0 && mx<v[k])cnt++;   
    mx=v[k];
    for(ll i=k+1;i<n;++i){
        mx=max(mx,v[i]);
        if(mx!=v[k])break;
        cnt++;
    }
    ans=max(ans,cnt);
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

