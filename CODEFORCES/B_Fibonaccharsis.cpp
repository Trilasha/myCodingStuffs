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



struct Matrix{
    ll a[2][2]={{0,0},{0,0}};
    Matrix operator *(const Matrix& other){
        Matrix product;
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    product.a[i][k]+=a[i][j]*other.a[j][k];
                    product.a[i][k]%=modval;
                }
            }
        }
        return product;
    }
};
 
Matrix expo_power(Matrix a, ll k){
    Matrix product;
    for(ll i=0;i<2;++i){
        product.a[i][i]=1;
    }
    while(k){
        if(k&1){
            product=product*a;
        }
        a=a*a;
        k>>=1;
    }
    return product;
}

void solve(){
    ll N,K;
    cin>>N>>K;
    
    //b
    ll n=K-1;
    ll bb=0;

    Matrix mat;
    mat.a[0][0]=0*0;
    mat.a[0][1]=1*1;
    mat.a[1][0]=1*1;
    mat.a[1][1]=1*1;
    Matrix ans=expo_power(mat,n);
    bb=ans.a[1][0];

    n=K-2;
    ll aa=0;
    Matrix matt;
    matt.a[0][0]=0*1;
    matt.a[0][1]=1*1;
    matt.a[1][0]=1*1;
    matt.a[1][1]=1*1;
    Matrix anss=expo_power(matt,n);
    aa=anss.a[1][0];

    //cout<<aa<<" "<<bb<<endl;
    ll cnt=0;

    for(ll i=0;i<=N;++i){
        ll x=i*aa;
        ll req=(N-x)/bb;
        if(req>=0 && (x+(bb*req))==N && i<=req){
            cnt++;
            //cout<<x<<" "<<req<<endl;
        }
    }
    cout<<cnt<<endl;

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
//    if 100% sure that chk func is correct then try changing the values of lo/hi in the main func (hit and trial)
/*----------------------------------------------------------------------------------------------------------- */



   
