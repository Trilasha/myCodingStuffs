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
//clear adj and visited vector declared globally after each test case 
//if input newly taken then use 'resize' or else 'assign' (for dp and graphs)
//    BINARY SEARCH ~ 2-PNTS ~ DP 
//    reference for sequence(NT) --> oeis.org
//    log2(x)
//    set.lower_bound(x)
//    for mod division --> a/b use a*inverse(b) (don't divide simply)
//    set<ll> adj[n+1]; --> for adjacency list (to handle erasing of elements)
//    gcd(x,y)=gcd(x-y,y) --->  gcd(x,y,z,...)=gcd(x-y,y,z,...)
//    a+b=2⋅(a&b)+a⊕bs
//    a⊕b=¬(a&b)&(a∣b)
/*----------------------------------------------------------------------------------------------------------- */





ll n,k;
vector<ll> v;

struct Matrix{
    vector<vector<ll>> a;
    Matrix(ll n,ll m){
        a.resize(n,vector<ll>(m,0));
    }
    Matrix operator *(const Matrix& other){
        ll x=a.size();
        ll y=a[0].size();
        ll z=other.a[0].size();
        Matrix product=Matrix(x,z);

        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                for(int k=0;k<z;k++){
                    product.a[i][k]+=a[i][j]*other.a[j][k];
                    product.a[i][k]%=modval;
                }
            }
        }
        return product;
    }
};
 
Matrix expo_power(Matrix a, ll k){
    Matrix product=Matrix(n,n);
    for(ll i=0;i<n;++i){
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
//Matrix mat=Matrix(n,n);
//Matrix res=expo_power(mat,k);
//mat.a[i][j]=1;
//O(k^3logN)




void solve(){
    cin>>n>>k;
    k--;
    v.resize(n);
    inpv(v);
    Matrix mat=Matrix(n,n);
    for(ll i=0;i<n;++i){
        for(ll j=0;j<n;++j){
            ll x=v[i]^v[j];
            ll one=bpl(x);
            if(one%3==0){
                mat.a[i][j]=1;
            }
        }
    }
    Matrix res=expo_power(mat,k);
    ll ans=0;
    fr(i,n){
        fr(j,n){
            ans+=res.a[i][j];
            ans%=modval;
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






   
