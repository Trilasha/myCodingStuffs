/*
    "When you are in darkness, listen to the whispers of your heart
    but when you are in light, listen to the thunder of your brain."
    
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
/*----------------------------------------------------------------------------------------------------------- */





void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    inpv(v);
    vector<pll> vp;
    fr(i,n){
        vp.pb({v[i]%k,v[i]});
    }
    sort(all(vp));

    ll ans=0;
    ll ok=0;
    if(n==1){
        cout<<0<<endl;
        return;
    }


    ll mark=-1;
    for(ll i=0;i<n;++i){
        if(i==n-1){
            if(ok){
                ans=-1;
            }else if(n%2)mark=vp[i].ff;
        }else{
            ll md1=vp[i].ff;
            ll md2=vp[i+1].ff;
            if(md1==md2){
                ans+=(vp[i+1].ss-vp[i].ss)/k;
                i++;
            }else{
                if(ok){
                    ans=-1;
                    break;
                }else{
                    mark=vp[i].ff;
                    ok=1;
                }
            }
        }
    }
    // cout<<ans<<endl;
    // line
    if(mark==-1 || ans==-1){
        cout<<ans<<endl;
        return;
    }
    // line
    vector<ll> temp;
    for(ll i=0;i<n;++i){
        if(vp[i].ff==mark){
            temp.pb(vp[i].ss);
        }
    }
    for(ll i=0;i<temp.size()-1;i+=2){
        ans-=(temp[i+1]-temp[i])/k;
    }
    ll sum=0;
    ll nn=temp.size();
    for(ll i=1;i<nn;i+=2){
        sum+=(temp[i+1]-temp[i])/k;
    }
    ll add=sum;
    for(ll i=0;i<nn;i+=2){
        if(i>0){
            sum-=(temp[i]-temp[i-1])/k;
        }
        add=min(add,sum);
        sum+=(temp[i+1]-temp[i])/k;
    }
    ans+=add;
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

