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
    vector<ll> v(n);
    inpv(v);
    ll i=0,j=n-1;
    ll cnt=0;
    // ll l=0,r=0;
    // while(i<=j){
    //     ll mn=min(v[i],v[j]);
    //     if(i==j){
    //         if(mn>=k)cnt++;
    //         break;
    //     }
    //     if(2*(mn-1)>=k)break;
    //     if(k==((2*mn)-1)){
    //         cnt++;
    //         break;
    //     }
    //     if(v[i]==mn && v[j]==mn){
    //         if(l==1){
    //             v[i]-=mn;
    //             j--;
    //             k-=2*mn;
    //             cnt++;
    //             if(v[i]==0){
    //                 cnt++;
    //                 i++;
    //             }
    //             l=0;
    //             r=1;
    //         }else{
    //             v[j]-=mn;
    //             i++;
    //             cnt++;
    //             k-=2*mn;    
    //             if(v[j]==0){
    //                 cnt++;
    //                 j--;
    //             }
    //             l=1;
    //             r=0;
    //         }
    //     }
    //     else if(v[i]==mn){
    //         v[j]-=mn;
    //         i++;
    //         cnt++;
    //         k-=2*mn;    
    //         if(v[j]==0){
    //             cnt++;
    //             j--;
    //         }
    //         l=1;
    //         r=0;
    //     }else{
    //         v[i]-=mn;
    //         j--;
    //         k-=2*mn;
    //         cnt++;
    //         if(v[i]==0){
    //             cnt++;
    //             i++;
    //         }
    //         l=0;
    //         r=1;
    //     }
    //     // cnt++;
    // }
    cout<<cnt<<endl;

 
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

