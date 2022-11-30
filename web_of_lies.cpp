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

ll chk=0;

void dfs(vector<vector<ll>> &adj,ll node,vector<ll> &vis,ll &ans)
{
    chk=0;
    for(auto &child:adj[node])
    {
       if(!vis[child])
        chk=1;
    }
    if(chk==1)
    {
    vis[node]=1;
    ans++;
    }
}

void solve()
{
  inp(v);
  inp(e);

  vector<vector<ll>> adj(v+1);

  for(ll i=0;i<e;++i)
  {
    ll x,y;
    cin>>x>>y;
    adj[x].pb(y);
    adj[y].pb(x);
  }

 
  ll ct=0;

  vector<ll> vis(v+1,0);
  ll ans=0;
    for(ll i=1;i<=v;++i)
    {
        dfs(adj,i,vis,ans);
    }
    ans=v-ans;
  inp(q);
  while(q--)
  {
    ll type;
    cin>>type;

    if(type==1)
    {
        ll n1,n2;
        cin>>n1>>n2;
        ll mini=min(n1,n2);
        ll maxy=max(n1,n2);
        ll chk=0;
        if(!vis[mini])
        {
            chk=1;
            vis[mini]=1;
            ans--;
        }
    }
    else if(type==2)
    {
       ll d1,d2;
       cin>>d1>>d2;
       ll mini1=min(d1,d2);
       ll maxy1=max(d1,d2);

       if(!vis[maxy1])
       {
        ans--;
        vis[maxy1]=1;
       }
       if(vis[mini1])
       {
        ans++;
        vis[mini1]=0;
       }
       
    }

    else 
    {
        cout<<ans<<endl;
    }
  }
}
    
int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);

    
ll q=1;
//cin>>q;
for(ll i=0;i<q;i++){
   // google(i+1);
    solve();
}
    return 0;
}















