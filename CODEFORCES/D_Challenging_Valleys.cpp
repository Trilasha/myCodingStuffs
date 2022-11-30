/*
Trilasha Mazumder
2112063
*/


/// ------------------------------------HEADER-FILES and ABBREVIATIONS---------------------------- ///
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
#define umap                  unordered_map
#define uset                  unordered_set
#define ff                    first
#define ss                    second
#define pi                    pair<ll,ll> 
#define maxpq                 priority_queue <ll> pq;
#define minpq                 priority_queue <ll, vector<ll>, greater<ll> > pq; 
/// ------------------------------------PRE-DEFINED VALUES---------------------------------------- ///
#define maxval                1000000007
#define PI                    3.141592653589793238
#define bpl(n)                __builtin_popcountll(n);
/// ------------------------------------TAKING INPUTS--------------------------------------------- ///
#define inp(n)                ll n;cin>>n;
#define inpv(v)               for(auto &x: v) cin>>x;
#define make(arr,n)           ll arr[n]; fr(i,n) cin>>arr[i];
/// ------------------------------------FOR LOOPS AND SORT---------------------------------------- ///
#define fr(i,n)               for (ll i=0;i<n;++i)
#define frs(i,k,n)            for(ll i=k;i<n;++i)
#define fA(i,a,n)             for(ll i=a;i<=(n);++i)
#define fD(i,a,n)             for(ll i=a;i>=(n);--i)
#define dsort(arr)            sort(arr,arr+n,greater<ll>())
#define asort(arr)            sort(arr,arr+n)
#define all(str)              str.begin(), str.end()
#define pll                   pair<ll,ll>


/// ------------------------------------NUMBER THEORY--------------------------------------------- ///
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
/*
vector<ll> v= sieve(1e5+10);
TC--> nloglogn
*/

/// ------------------------------------PRINTOUTS------------------------------------------------- ///
#define printv(v)             for(auto &i: v){cout << i << " ";} cout << endl;
#define printmap(mp)          for(auto &i: mp){cout << i.first << " "<<i.second<<endl;}
#define printset(st)          for(auto &i: st){cout << i << " ";} cout << endl;
#define line                  cout<<"----------------------------------------"<<endl;
void google(ll t) {cout << "Case #" << t << ": ";}

/// ---------------------------------------------------------------------------------------------- ///

    


void solve()
{
  inp(n);
  vector<ll> v(n);
  inpv(v);


  set<ll> s;
  fr(i,n)
  s.insert(v[i]);

  if(s.size()==1)
  {
    cout<<"YES"<<endl;
    return;
  }


//   map<ll,ll> mp;

//   fr(i,n)
//   {
//     mp[v[i]]++;
//   }

  vector<ll> copy;

  copy.pb(v[0]);
  ll var=v[0];
  for(ll i=1;i<n;++i)
  {
    if(v[i]!=var)
    {
        copy.pb(v[i]);
        var=v[i];
    }
  }
 //printv(copy);
//   line

  if(copy.size()==2)
  {
    cout<<"YES"<<endl;
    return;
  }



  ll left=0;
  ll right=0;
  ll whole=0;

  ll mid=0;
  ll cnt=0;


if(copy[0]<copy[1])
left=1;

if(copy[copy.size()-2]>copy[copy.size()-1])
right=1;

//printv(copy);
for(ll i=1;i<(copy.size()-1);++i)
{
    if(copy[i-1]>copy[i]  && copy[i]<copy[i+1])
    cnt++;
}
// cout<<cnt<<endl;
// line

if(cnt==0 && left==0 && right==0)
{
    cout<<"NO"<<endl;
    return;
}

if(cnt==0 && left==0 && right==1)
{
 cout<<"YES"<<endl;
    return;
}
if(cnt==0 && left==1 && right==0)
{
 cout<<"YES"<<endl;
    return;
}
if(cnt==1 && left==0 && right==0)
{
 cout<<"YES"<<endl;
    return;
}

cout<<"NO"<<endl;

}
    
int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);

    
ll q=1;
cin>>q;
for(ll i=0;i<q;i++){
   // google(i+1);
    solve();
}
    return 0;
}















