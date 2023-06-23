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
    ll r,c;
    cin>>r>>c;
    vector<string> v(r);
    fr(i,r){
        cin>>v[i];
    }

    ll rk=0;
    ll ck=0;
    ll di=0;
    pll p;

    for(ll i=0;i<r;++i){
        string temp=v[i];
        for(ll j=0;j<(c-5);++j){
            if(temp.substr(j,5)=="snuke"){
                p.pb({i,j});
                rk=1;
                break;
            }
        }
    }

    if(rk==1){
        ll rr=p.ff+1;
        ll cc=p.ss+1;
        cout<<rr<<" "<<cc<<endl;
        cout<<rr<<" "<<cc+1<<endl;
        cout<<rr<<" "<<cc+2<<endl;
        cout<<rr<<" "<<cc+3<<endl;
        cout<<rr<<" "<<cc+4<<endl;
        return;
    }

    
    for(ll i=0;i<c;++i){
        string temp="";
        for(ll j=0;j<r;++j)
        temp+=v[j][i];

        for(ll j=0;j<(r-5);++j){
            if(temp.substr(j,5)=="snuke"){
                p.pb({j,i});
                ck=1;
                break;
            }
        }
    }

    if(ck==1){
        ll rr=p.ff+1;
        ll cc=p.ss+1;
        cout<<rr<<" "<<cc<<endl;
        cout<<rr+1<<" "<<cc<<endl;
        cout<<rr+2<<" "<<cc<<endl;
        cout<<rr+3<<" "<<cc<<endl;
        cout<<rr+4<<" "<<cc<<endl;
        return;
    }


    
    for(ll i=0;i<c-5;++i){
        string temp="";
        for(ll )
    }

    if(rk==1){
        ll rr=p.ff+1;
        ll cc=p.ss+1;
        cout<<rr<<" "<<cc<<endl;
        cout<<rr<<" "<<cc+1<<endl;
        cout<<rr<<" "<<cc+2<<endl;
        cout<<rr<<" "<<cc+3<<endl;
        cout<<rr<<" "<<cc+4<<endl;
        return;
    }

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