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
// #define md                    998244353
#define modval                1000000007
#define endl                " \n"
/*----------------------------------------------------------------------------------------------------------- */






string hehe="Just a legend";
vector<ll> hash1,power1(2e6+10,1);
vector<ll> invMod1(2e6+10,1);

ll radix=31;
ll mod=1e9+7;

ll expo(ll b,ll e,ll md){
    ll ans=1;
    while(e){
        if(e&1) ans=(ans*b)%md;
        b=(b*b)%md;
        e/=2;
    }
    return ans;
}
void precal(string &s){
    int n=s.size();
    hash1.resize(n+5);
    ll a=1;
    for(int x=0;x<n;++x){
        hash1[x+1]=(hash1[x]+(s[x]-'a'+1)*a)%mod;
        a=(a*radix)%mod;
    }
}

ll invmod(ll p){
    return expo(p,mod-2,mod);
}
void preInv(){
    for(int i=1;i<=1e6+1;i++){
        power1[i]=(power1[i-1]*radix)%mod;
        invMod1[i]=invmod(power1[i]);
    }
}

ll calc(ll left,ll right){
    ll val=(hash1[right]-hash1[left-1]+mod)%mod;
    ll ans=(val*invMod1[left-1])%mod;
    return ans;
}




bool check(ll mid,string &s){
    ll n=s.size();
    ll val=calc(1,mid);
    ll ok=1;
    for(ll i=2;i<=n-mid+1;++i){
        ll a=calc(i,i+mid-1);
        if(a==val) ok++;
        if(ok==3)break;
    }
    return (ok==3);
}


void solve(){
    string s;
    cin>>s;
    ll n=s.size();
    if(s.size()<3){
        cout<<hehe<<endl;
        return;
    }
    preInv();
    precal(s);
   
    ll low=1;
    ll high=n;
    ll len=-1;

    while(low<=high){
        ll mid=(low+high)/2;
        if(check(mid,s)){
            len=mid;
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    for(ll x=len;x>=1;--x){
        if(calc(1,x)==calc(n-x+1,n)){
            cout<<s.substr(0,x)<<endl;
            return;
        }
    }
    cout<<hehe<<endl;
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

