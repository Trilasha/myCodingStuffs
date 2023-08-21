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
  vector<vector<char>> v(3,vector<char>(3));
  fr(i,3){
    fr(j,3){
        cin>>v[i][j];
    }
  }
  ll X=0;
  ll O=0;
  ll plus=0;

  for(ll i=0;i<3;++i){
    if(v[i][0]=='X' && v[i][1]=='X' && v[i][2]=='X')X++;
    if(v[i][0]=='O' && v[i][1]=='O' && v[i][2]=='O')O++;
    if(v[i][0]=='+' && v[i][1]=='+' && v[i][2]=='+')plus++;
  }

  for(ll i=0;i<3;++i){
    if(v[0][i]=='X' && v[1][i]=='X' && v[2][i]=='X')X++;
    if(v[0][i]=='O' && v[1][i]=='O' && v[2][i]=='O')O++;
    if(v[0][i]=='+' && v[1][i]=='+' && v[2][i]=='+')plus++;
  }

    if(v[0][0]=='X' && v[1][1]=='X' && v[2][2]=='X')X++;
    if(v[0][0]=='O' && v[1][1]=='O' && v[2][2]=='O')O++;
    if(v[0][0]=='+' && v[1][1]=='+' && v[2][2]=='+')plus++;

    if(v[0][2]=='X' && v[1][1]=='X' && v[2][0]=='X')X++;
    if(v[0][2]=='O' && v[1][1]=='O' && v[2][0]=='O')O++;
    if(v[0][2]=='+' && v[1][1]=='+' && v[2][0]=='+')plus++;

    if(X==0 and O==0 and plus!=0){
        cout<<'+'<<endl;
        return;
    }
    if(X==0 and O!=0 and plus==0){
        cout<<'O'<<endl;
        return;
    }
    if(X!=0 and O==0 and plus==0){
        cout<<'X'<<endl;
        return;
    }
    cout<<"DRAW"<<endl;
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



   
