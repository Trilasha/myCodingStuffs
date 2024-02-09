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
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    // iota(all(v),1);
    // printv(v);
    // do{
    //     vector<ll> chk;
    //     ll sum=0;
    //     for(ll i=0;i<k;++i){
    //         sum+=v[i];
    //     }
    //     chk.pb(sum);
    //     for(ll i=k;i<n;++i){
    //         sum+=v[i];
    //         sum-=v[i-k];
    //         chk.pb(sum);
    //     }
    //     ll mx=*max_element(all(chk));
    //     ll mn=*min_element(all(chk));
    //     if((mx-mn)<=1){
    //         cout<<mx<<" "<<mn<<endl;
    //         printv(v);
    //     }
    // }while(next_permutation(all(v)));
    vector<ll> temp(n);
    temp[0]=n;
    temp[1]=1;
    for(ll i=0;i<k;++i){
        if(!(i%2)){
            ll curr=temp[i],mx=curr,mn=n+1;
            ll last=curr;
            for(ll j=i;j<n;j+=k){
                v[j]=curr;
                last=v[j];
                curr--;
            }
            mn=last;
            if((i+2)<k){
                temp[i+2]=mn-1;
            }
        }else{
            ll curr=temp[i],mn=curr,mx=0;
            ll last=curr;
            for(ll j=i;j<n;j+=k){
                v[j]=curr;
                last=v[j];
                curr++;
            }
            mx=last;
            if((i+2)<k){
                temp[i+2]=mx+1;
            }
        }
    }
    printv(v);
 
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

