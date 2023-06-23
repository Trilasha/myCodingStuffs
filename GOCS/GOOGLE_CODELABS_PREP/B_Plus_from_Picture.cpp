/*
Trilasha Mazumder
2112063
*/


/// ------------------------------------HEADER-FILES and ABBREVIATIONS---------------------------- ///
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 


using namespace std;
using namespace __gnu_pbds;

typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds; 


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
void google(ll t) {cout << "Case #" << t << ": ";}


void avoid_error()
{
/*
when the ans vector contains modulated values,then take the modulo(%) while calculating the elements' value...DON'T JUST PUT % AT THE TIME OF INSERTION 
CORRECT                     :-loop-->anss=(anss*powers[j])%(nn); then ans.pb(anss);
WRONG(tle,rte or wa)        :-loop-->anss=(anss*powers[j]); then ans.pb(anss%nn);
AVOID creating any prefix product array in case of modulo problems

-->take size +1(atleast extra) for vectors to avoid out of bounds

-->ll suma=accumulate(all(a),0LL);
//put OLL or else WA for larger sum
*/
}


    


void solve()
{
 ll r,c;
 cin>>r>>c;
 vector<vector<char>> v(r,vector<char>(c));
 //'.' --> 1
 //'*' --> 2

 for(ll i=0;i<r;++i)
 {
    for(ll j=0;j<c;++j)
    {
        // char ch;
        // cin>>ch;
        // if(ch=='.')
        // v[i][j]=1;
        // else
        // v[i][j]=2;
        cin>>v[i][j];
    }
 }
vector<vector<ll>> vis(r,vector<ll>(c,0));
ll cl=0;
ll cr=0;
ll ct=0;
ll cb=0;
ll ccell=0;

ll ans=0;
ll mainchk=0;

for(ll i=1;i<r-1;++i)
{
    for(ll j=1;j<c-1;++j)
    {
        ccell=0;
        if(v[i][j]=='*')
        {
            //vis[i][j]=1;
            ccell=1;

            if(v[i+1][j]=='*' && v[i-1][j]=='*' && v[i][j+1]=='*' && v[i][j-1]=='*')
            mainchk=1;
            if(mainchk==1)
            {

            //going right
            vis[i][j]=1;
            for(ll a=j+1;a<c;++a)
            {
                if(v[i][a]=='.')
                break;
                if(v[i][a]=='*')
                {
                vis[i][a]=1;
                cr=1;
                }
            }
             //going left
            for(ll b=j-1;b>=0;--b)
            {
                if(v[i][b]=='.')
                break;
                if(v[i][b]=='*')
                {
                vis[i][b]=1;
                cl=1;
                }
            }
             //going top
            for(ll c=i-1;c>=0;--c)
            {
                if(v[c][j]=='.')
                break;
                if(v[c][j]=='*')
                {
                vis[c][j]=1;
                ct=1;
                }
            }
             //going bottom
            for(ll d=i+1;d<r;++d)
            {
                if(v[d][j]=='.')
                break;
                if(v[d][j]=='*')
                {
                vis[d][j]=1;
                cb=1;
                }
            }

            ans=1;
            break;
         }

        }
    }
    if(ans==1)
    break;
}
if(mainchk==0)
{
    cout<<"NO"<<endl;
    return;
}

for(ll i=0;i<r;++i)
{
    for(ll j=0;j<c;++j)
    {
        if(v[i][j]=='*' && vis[i][j]==0)
        {
            cout<<"NO"<<endl;
            return;
        }
    }
}
cout<<"YES"<<endl;
return;

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















