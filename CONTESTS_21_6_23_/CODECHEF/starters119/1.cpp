/*
    When talent doesn't work hard then hardwork beats talent...
    ...hardwork always pays off
*/


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
// insead of bpow use shift operators when b=2 to avoid tle 
// do not perform more than one optimal choice/ops in a single step/loop otherwise break your head with WA



map<ll,ll> mp;
set<ll> printprimefactors(ll n){
    set<ll> st;
    if(n<=1) return st;
    while(n%2==0){
        st.insert(2);
        mp[2]++;
        n=n/2;
    }
     while(n%3==0){
        st.insert(3);
        mp[3]++;
        n=n/3;
    }
    for (ll i = 5; i*i<=n; i=i+6){
        while (n%i==0){
            st.insert(i);
            mp[i]++;
            n=n/i;
        }
        while(n%(i+2)==0){
            st.insert(i+2);
            mp[i+2]++;
            n=n/(i+2);
        }
    }
    if(n>3){
        st.insert(n);
        mp[n]++;
    }
    return st;
    //i/p-->450
    //o/p-->23355
}
//tc-theta(sqrt(n))

ll bpow(ll a,ll b){
    ll res=1;
    while(b>0){
        if(b&1){
            res=(res*a)%modval;
        }
        a=(a*a)%modval;
        b=b>>1;
    }
    return res;
}

void solve(){
    mp.clear();
    ll x,n;
    cin>>x>>n;
    vector<ll> v(n);
    fr(i,n){
        cin>>v[i];
    }
    set<ll> st=printprimefactors(x);
    // ll cnt=0;
    // printset(st);
    for(auto &i:v){
        ll cnt=0;
        for(auto &j:st){
            if(mp[j]%i==0 && i!=1){
                cnt++;
            }
        }
        cout<<bpow(2,cnt)<<endl;
    }
 
}


int main(){

fast_io;

// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

ll q=1;
cin>>q;
for(ll i=0;i<q;i++){
    solve();
}
    return 0;
}

