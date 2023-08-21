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
//#define endl                " \n"
/*----------------------------------------------------------------------------------------------------------- */




void solve(){
    ll n,q;
    cin>>n>>q;
    map<ll,map<ll,ll>> v;
    vector<pll> dxy={{1,0},{-1,0},{0,1},{0,-1}};
    map<ll,ll> sum;
  
    fr(i,q){
        ll x,y,val;
        cin>>x>>y>>val;
        x--;y--;

        if(val==0){
            for(auto &j:dxy){
            ll nx=x+j.ff;
            ll ny=y+j.ss;
            if(nx>=0 && nx<n && ny>=0 && ny<n){
                ll curr=v[x][y]+v[nx][ny];
                //cerr<<curr<<" "<<sum[curr]<<endl;
                   if(curr>v[x][y]){
                       sum[curr]--;
                       if(sum[curr]==0)
                       sum.erase(curr);
                   }
            }
        }
        // cout<<sum.size()<<endl;
        // for(auto &j:sum){
        //     cerr<<j.ff<<" "<<j.ss<<endl;
        // }

        v[x][y]=val;
        }        

        if(val){
            //v[x][y]=val;
            for(auto &j:dxy){
            ll nx=x+j.ff;
            ll ny=y+j.ss;
            if(nx>=0 && nx<n && ny>=0 && ny<n){
                ll curr=v[x][y]+v[nx][ny];
                //cerr<<curr<<" "<<sum[curr]<<endl;
                   if(curr>v[x][y]){
                       sum[curr]--;
                       if(sum[curr]==0)
                       sum.erase(curr);
                   }
            }
            }

            v[x][y]=val;
            for(auto &j:dxy){
                ll nx=x+j.ff;
                ll ny=y+j.ss;
                if(nx>=0 && nx<n && ny>=0 && ny<n){
                    ll curr=v[x][y]+v[nx][ny];
                    //cerr<<curr<<endl;
                    if(curr>v[x][y]){
                        //cerr<<curr<<endl;
                        sum[curr]++;
                    }
                }
            }
            // cerr<<sum.size()<<endl;
            // cout<<sum.size()<<endl;
            // for(auto &j:sum){
            //     cerr<<j.ff<<" "<<j.ss<<endl;
            // }
            //v[x][y]=val;
        }
        
        if(sum.size()==1){
            for(auto &i:sum){
                if(i.ss>1){
                    cout<<"YES"<<endl;
                }else{
                    cout<<"NO"<<endl;
                }
            }
        }else{
            if(sum.size()==0){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }


    }
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









/*----------------------------------------------------------------------------------------------------------- */
// clear adj and visited vector declared globally after each test case 
// if input newly taken then use 'resize' or else 'assign' (for dp and graphs)
//    BINARY SEARCH ~ 2-PNTS ~ DP 
//    reference for sequence(NT) --> oeis.org
//    log2(x)
//    set.lower_bound(x)
//    for mod division --> a/b use a*inverse(b) (don't divide simply)
//    set<ll> adj[n+1]; --> for adjacency list (to handle erasing of elements)
//    gcd(x,y)=gcd(x-y,y) --->  gcd(x,y,z,...)=gcd(x-y,y,z,...)
//    if nlogn approach gives tle, go for O(n) don't sit idle (for lb/ub replace set with vector)
/*----------------------------------------------------------------------------------------------------------- */



   
