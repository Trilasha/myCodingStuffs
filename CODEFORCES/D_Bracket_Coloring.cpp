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
//set.lower_bound(x)
//for mod division --> a/b use a*inverse(b) (don't divide simply)
//set<ll> adj[n+1]; --> for adjacency list (to handle erasing of elements)
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
/// --------------------------------------------------------------------------------------------------------- ///


void solve(){
     ll n;
     cin>>n;
     string s;
     cin>>s;

     ll open= count(all(s),'(');
     ll close= count(all(s),')');

     ll vall=n%2;

     if(vall!=0 || open!=close){
          cout<<-1<<endl;
          return;
     }

     stack<pair<char,ll>> aa,bb;

     
     vector<ll> coly(n,0);

     ll tt=0,ans=0;
     if(s[0]=='('){
    fr(i,n){
        if(s[i]=='('){
            aa.push({'(',i});
        }
    else{
        if(aa.empty()){
                if(s[i]==')'){
                    bb.push({')',i});
                }       
        }
        else{
                coly[i]=1;
                coly[aa.top().second]=1;
                tt=1;
                aa.pop();
        }
    }
    }
     }
     else
     {
    fr(i,n){
        if(s[i]==')'){
            aa.push({')',i});
        }
        else{
            if(aa.empty()){
                    if(s[i]=='('){
                        bb.push({'(',i});
                    }       
            }
            else{
                    coly[i]=1;
                    coly[aa.top().second]=1;
                    tt=1;
                    aa.pop();
            }
        }
    }

     }
     while(!bb.empty() and !aa.empty()){
          coly[bb.top().second]=2;
          coly[aa.top().second]=2;
          bb.pop();
          aa.pop();
     }

     ll val=count(all(coly),2);
     if(val==0 || val==n){
          cout<<1<<endl;
          for(auto var: coly){
               cout<<1<<" ";
          }
          cout<<endl;
          return;
     }

     cout<<2<<endl;
     for(auto var: coly){
          cout<<var<<" ";
     }


     cout<<endl;
    
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


/// --------------------------------------------------------------------------------------------------------- ///
//reference for sequence(NT) --> oeis.org
//log2(x)
//give separate condition checks for smaller values of n(like n<=2)
//never use = sign in comparator functions
//the real challenge of bs --> selection of lo and hi
//set.lower_bound(x)
//for mod division --> a/b use a*inverse(b) (don't divide simply)
//set<ll> adj[n+1]; --> for adjacency list (to handle erasing of elements)
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
/// --------------------------------------------------------------------------------------------------------- ///