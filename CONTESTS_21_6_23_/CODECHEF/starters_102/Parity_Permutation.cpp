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
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    inpv(v);
    ll odd=0,even=0;
    vector<ll> O,E;
    for(auto &i:v){
        if(i%2){
            odd++;
            O.pb(i);
        }
        else{
            even++;
            E.pb(i);
        }
    }
    if(k==0){
        if(odd>0 && even>0){
            cout<<0<<endl;
            return;
        }
        ll ans=1;
        ll mx=max(even,odd);
        for(ll i=0;i<n;++i){
            ans=(ans*mx)%modval;
            mx--;
        }
        cout<<ans<<endl;
    }else{
        ll ans=0;
        ll fin=0;
        vector<ll> temp;
        ll ok=0;
        // 0 pe odd and 1 pe even
        ll oddpos=(n+1)/2;
        ll evenpos=n-oddpos;
        ll oriodd=odd;
        ll orieven=even;
        if(oddpos==odd && evenpos==even){
            ans=1;
            ok=1;
            for(ll i=0;i<n;i+=2){
                ans=(ans*odd)%modval;
                odd--;
            }
            for(ll i=1;i<n;i+=2){
                ans=(ans*even)%modval;
                even--;
            }
        }
        fin=ans;
        //cout<<fin<<endl;
        ans=0;
        odd=oriodd;
        even=orieven;
        //cout<<oddpos<<" "<<even<<" "<<evenpos<<" "<<odd<<endl;
        if(oddpos==even && evenpos==odd){
            ans=1;
            ok=1;
            for(ll i=1;i<n;i+=2){
                ans=(ans*odd)%modval;
                odd--;
            }
            for(ll i=0;i<n;i+=2){
                ans=(ans*even)%modval;
                even--;
            }
        }
        fin=(fin+ans)%modval;
        if(ok==0){
            cout<<0<<endl;
            return;
        }
        cout<<fin<<endl;
    }
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

