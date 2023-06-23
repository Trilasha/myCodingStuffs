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
//#define endl                  " \n"
/// --------------------------------------------------------------------------------------------------------- ///

/// --------------------------------------------------------------------------------------------------------- ///
//reference for sequence(NT) --> oeis.org
//log2(x)
//give separate condition checks for smaller values of n(like n<=2)
//never use = sign in comparator functions
//the real challenge of bs --> selection of lo and hi
//set.lower_bound(x)
//for mod division --> a/b use a*inverse(b) (don't divide simply)
//set<ll> adj[n+1]; --> for adjacency list (to handle erasing of elements)
//gcd(x,y)=gcd(x-y,y) --->  gcd(x,y,z,...)=gcd(x-y,y,z,...)
/// --------------------------------------------------------------------------------------------------------- ///





void solve(){
   ll ax,ay,bx,by;
   cin>>ax>>ay>>bx>>by;
   if(ax==0 && bx==0 && ((ay>0 && by>0) || (ay<0 && by<0))){
       cout<<abs(ay-by)<<endl;
       return;
   }

    if(ay==0 && by==0 && ((ax>0 && bx>0) || (ax<0 && bx<0))){
       cout<<abs(ax-bx)<<endl;
       return;
   }

   double str=abs(ax-0)+abs(ay-0)+abs(bx-0)+abs(by-0);
   double curve=0;


   ll mn;
   if(ax==0 && bx==0){
        mn=min(abs(ay),abs(by));
   }else if(ay==0 && by==0){
        mn=min(abs(ax),abs(bx));
   }else{
        mn=max(abs(bx),abs(by));
        mn=min(mn,max(abs(ax),abs(ay)));
        ax=abs(ax);
        bx=abs(bx);
        ay=abs(ay);
        by=abs(by);
   }

   if(ax==0 && bx==0){
    curve=abs(abs(ay)-abs(by))+(PI*mn);
   }else if(ay==0 && by==0){
    curve=abs(abs(ax)-abs(bx))+(PI*mn);
   }else{
        curve=abs(ax-by)+abs(ay-bx)+0.25*(2*PI*mn);
    }
    //cout<<curve<<endl;
    if(str<=curve){
        cout<<str<<endl;
    }else{
        cout<<sp(6)<<curve<<endl;
    }
    //line

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