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



bool isPrime(ll n)
{
 if(n==1) return false;
if(n==2 || n==3) return true;
if(n%2==0 || n%3==0) return false;
for(ll i=5;i*i<=n;i=i+6)
if(n%i==0 || n%(i+2)==0)
return false;
return true;
}

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> v(n,vector<ll>(m,0));
    ll pro=n*m;

    if(!isPrime(n)){
        for(ll i=0;i<m;++i){
            for(ll j=0;j<n;++j){
                v[j][i]=pro;
                pro--;
            }
        }


    }else if(!isPrime(m)){
        for(ll i=0;i<n;++i){
            for(ll j=0;j<m;++j){
                v[i][j]=pro;
                pro--;
            }
        }
    }else{

        //both prime
        ll left=1;
        ll right=m+1;
        for(ll i=0;i<=n/2;++i){
            // ll ori=left;
            for(ll j=0;j<m;++j){
                v[i][j]=left;
                left++;
            }
            left+=m;;
        }
        for(ll i=n/2+1;i<n;++i){
            // ll orii=right;
            for(ll j=0;j<m;++j){
                v[i][j]=right;
                right++;
            }
            right+=m;
        }
    }

    for(ll i=0;i<n;++i){
        for(ll j=0;j<m;++j){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
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

ll maximum_subarray_sum(vector<ll> &v)
{
    ll ans=0;
    ll var=INT_MIN;
    fr(i,v.size())
    {
        var=max(v[i],var+v[i]);
        ans=max(ans,var);
    }
    return ans;
}
