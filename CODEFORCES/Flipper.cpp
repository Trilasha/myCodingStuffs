#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp> 


using namespace std;
//using namespace __gnu_pbds;
//typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds; 

           
#define ll                    long long
#define ld                    long double
#define pb                    push_back
#define popb                  pop_back
#define lb                    lower_bound
#define ub                    upper_bound
#define ff                    first
#define ss                    second
#define maxpq                 priority_queue <ll> pq;
#define minpq                 priority_queue <ll, vector<ll>, greater<ll> > pq; 
#define sp(x)                 fixed<<setprecision(x)
/// ---------------------------------------------------------------------------------------------------------- ///
#define md                    998244353
#define modval                1000000007
#define PI                    3.141592653589793238
#define bpl(n)                __builtin_popcountll(n);
/// ---------------------------------------------------------------------------------------------------------- ///
#define inp(n)                ll n;cin>>n;
#define inpv(v)               for(auto &x: v) cin>>x;
#define make(arr,n)           ll arr[n]; fr(i,n) cin>>arr[i];
/// ---------------------------------------------------------------------------------------------------------- ///
#define fr(i,n)               for (ll i=0;i<n;++i)
#define frs(i,k,n)            for(ll i=k;i<n;++i)
#define all(str)              str.begin(), str.end()
#define pll                   pair<ll,ll>
/// --------------------------------------------------------------------------------------------------------- ///
#define printv(v)             for(auto &i: v){cout << i << " ";} cout << endl;
#define printmap(mp)          for(auto &i: mp){cout << i.first << " "<<i.second<<endl;}
#define printset(st)          for(auto &i: st){cout << i << " ";} cout << endl;
#define line                  cout<<"----------------------------------------"<<endl;
#define arrow                 cout<<"--->";
#define debugmap(mp)             for(auto &i: mp){cout << i.ff << "-->" << i.ss <<endl;} cout << endl;
#define debugset(st)             for(auto &i: st){cout << i << " ";} cout << endl;
#define fast_io               ios_base::sync_with_stdio(false);cin.tie(NULL);

/// --------------------------------------------------------------------------------------------------------- ///
//reference for sequence(NT) --> oeis.org
//log2(x)
//give separate condition checks for smaller values of n(like n<=2)
//never use = sign in comparator functions
//the real challenge of bs --> selection of lo and hi
/// --------------------------------------------------------------------------------------------------------- ///





void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    inpv(v);
    vector<ll> ans;

    if(n==1){
        cout<<1<<endl;
        return;
    }

    if(n==2){
        if(v[0]==2){
        cout<<1<<" "<<2<<endl;
        }else{
        cout<<2<<" "<<1<<endl;
        }
        return;
    }

    if(v[0]==n){
        ll fi=-1;
        ll kk=0;
        fr(i,n){
        if(v[i]==(n-1)){
            fi=i;
            kk=1;
            ans.pb(v[i]);
        }else if(kk==1){
            ans.pb(v[i]);
        }
        }

        if(fi!=(n-1)){
        ans.pb(v[fi-1]);
        for(ll i=0;i<(fi-1);++i)
        ans.pb(v[i]);
        }
        else{
            for(ll i=0;i<fi;++i)
            ans.pb(v[i]);
        }
        printv(ans);
        return;
    }


    //
    if(v[n-1]==n){
        ll j=n-1;
        ll i=0;
        ll chk=0;
        while(j>=0){
            if(v[j]>=v[0]){
                ans.pb(v[j]);
                j--;
            }else{
                break;
            }
    }

    for(ll i=0;i<=j;++i)
    ans.pb(v[i]);
    printv(ans);
    return;
    }



    ll ok=0;
    ll ind=0;
    fr(i,n){
        if(v[i]==(n)){
            ind=i;
            ok=1;
            ans.pb(v[i]);
        }else if(ok==1){
            ans.pb(v[i]);
        }
    }

    // if(ind==0){
    //     printv(ans);
    //     return;
    // }

    // if(v[0]>v[ind-1] && v[n-1]==n){
    //     for(ll i=0;i<ind;++i)
    //     ans.pb(v[i]);
    //     printv(ans);
    //     return;
    // }

    ans.pb(v[ind-1]);
    if(ind<=1){
        printv(ans);
        return;
    }

    ll j=ind-2;
    ll i=0;
    ll chk=0;
    while(j>=0){
        if(v[j]>=v[0]){
            ans.pb(v[j]);
            j--;
        }else{
            break;
        }
    }

    for(ll i=0;i<=j;++i)
    ans.pb(v[i]);
    printv(ans);

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