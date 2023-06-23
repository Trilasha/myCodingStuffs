/* Trilasha Mazumder */

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
// define endl                " \n"
/*----------------------------------------------------------------------------------------------------------- */





ll maximum_subarray_sum(vector<ll> &v)
{
    ll ans=-1e12;
    ll var=INT_MIN;
    fr(i,v.size())
    {
        var=max(v[i],var+v[i]);
        ans=max(ans,var);
    }
    return ans;
}

void solve(){
    ll n;
    cin>>n;
    vector<vector<ll>> v(n,vector<ll>(n));
    fr(i,n){
        fr(j,n){
            cin>>v[i][j];
        }
    }

    vector<vector<ll>> row(n,vector<ll>(n));
    vector<ll> col(n);
    
    for(ll i=0;i<n;++i){
        for(ll j=0;j<n;++j){
            col[j]+=v[i][j];
            if(j==0){
                row[i][j]=v[i][j];
            }else{
                row[i][j]=row[i][j-1]+v[i][j];
            }
        }
    }
    for(ll i=1;i<n;++i){
        col[i]+=col[i-1];
    }

   // printv(col);
    

    ll ans=-1e12;

    for(ll i=0;i<n;++i){
        for(ll j=i;j<n;++j){
            ll curr=col[j];
            if(i!=0){
                curr-=col[i-1];
            }

            vector<ll> temp;
            for(ll k=0;k<n;++k){
                ll sum=row[k][n-1];
                ll to_minus=row[k][j];
                if(i!=0){
                    to_minus-=row[k][i-1];
                }
                sum-=to_minus;
                temp.pb(sum);
            }
            curr+=maximum_subarray_sum(temp);
            ans=max(ans,curr);
        }
    }

    cout<<ans<<endl;

}


int main(){

fast_io;

ll q=1;
//cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}











/*--------------------------------------------------------------------------------------------------------- 
   reference for sequence(NT) --> oeis.org
   log2(x)
   set.lower_bound(x)
   for mod division --> a/b use a*inverse(b) (don't divide simply)
   set<ll> adj[n+1]; --> for adjacency list (to handle erasing of elements)
   gcd(x,y)=gcd(x-y,y) --->  gcd(x,y,z,...)=gcd(x-y,y,z,...)
   --------------------------------------------------------------------------------------------------------- */