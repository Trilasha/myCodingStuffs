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






/*-----------------------------------------------Number theory Starts-----------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
ll bpow(ll base,ll power){ll res=1;while(power){if(power&1){res *= base;power--;}else{base *= base;power /=2;}}return res;}
bool power_of_two(ll x){ return x && (!(x&(x-1)));}
ll nearest_power_of_two(ll x){ ll ans = 1; while(ans<x){ ans <<= 1;}return ans;}
/*-----------------------------------------------Number theory Ends---------------------------------------------------------------*/


map<pair<ll,ll>,ll> mp;
map<pair<ll,ll>,pair<ll,ll>> par;
vector<pair<ll,ll>> dxy={{-1,0},{1,0},{0,-1},{0,1}};
void dfs(ll x,ll y,ll row,ll col,vector<vector<ll>> &grid,ll &cnt,pair<ll,ll> &p){
    if(x<0 || x>=row || y<0 || y>=col){
            return;
    }
    if(grid[x][y]<=0) return;
    par[{x,y}]=p;
    grid[x][y]=-1;
    cnt++;
    for(auto &dir:dxy){
        int nx=x+dir.first;
        int ny=y+dir.second;
        dfs(nx,ny,row,col,grid,cnt,p);
    }
}
void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> grid(n,vector<ll>(m));
    ll red=0;
    vector<string> v(n);
    fr(i,n){
        string s;
        cin>>s;
        v[i]=s;
    }
    // fr(i,n){
    //     cout<<v[i]<<endl;
    // }
    fr(i,n){
        fr(j,m){
            char ch=v[i][j];
            if(ch=='#'){
                grid[i][j]=1;
            }
            else {
                grid[i][j]=0;
                red++;
            }
        }
    }

    vector<vector<ll>> gg=grid;
    // fr(i,n){
    //     fr(j,m){
    //         cout<<gg[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    ll ans=0;
    for(ll x=0;x<n;++x){
        for(ll y=0;y<m;++y){
            if(grid[x][y]==1){
                ll cnt=0;
                pll p={x,y};
                par[p]=p;
                dfs(x,y,n,m,grid,cnt,p);
                mp[p]=cnt;
            }
        }
    }
        // for(auto &i:mp){
        //     cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<endl;
        // }
    ll tot=mp.size();
    vector<ll> temp;
    // cout<<tot<<endl;
    for(ll x=0;x<n;++x){
        for(ll y=0;y<m;++y){
            // cout<<gg[x][y]<<" ";
            if(gg[x][y]==0){
                // line
                set<pll> st;
                for(auto &dir:dxy){
                    ll nx=x+dir.first;
                    ll ny=y+dir.second;
                    if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==-1){
                        st.insert(par[{nx,ny}]);
                    }
                }
                //cout<<tot<<" "<<st.size()<<endl;
                ans+=tot-(ll)st.size()+1;
            }
        }
        // cout<<endl;
    }
    // cout<<ans<<" "<<red<<endl;
    ll fin=mod_div(ans,red,md);
    cout<<fin<<endl;

}


int main(){

fast_io;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

ll q=1;
// cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}

