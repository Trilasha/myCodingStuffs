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
#define endl                " \n"
/*----------------------------------------------------------------------------------------------------------- */






bool check(ll mid,vector<ll>&v,ll k,__int128_ H){
    ll sum=accumulate(all(v),0LL);
    __int128_ pro=(mid-1)*sum;
    H+=pro;
    for(ll i=0;i<k;++i){
        if(H<=0) return 1;
        H+=v[i];
    }
    return (H<=0);
}
void solve(){
    ll h,k;
    cin>>h>>k;
    vector<ll> v(k);
    inpv(v);
    ll sum=0;
    ll ori=h;
    for(ll i=0;i<k;++i){
        ori+=v[i];
        if(ori<=0){
            cout<<i+1<<endl;
            return;
        }
        sum+=v[i];
    }
    if(sum>=0){
        cout<<-1<<endl;
        return;
    }

    ll low=1;
    ll high=1e12;
    ll ans=1e17;
    while(low<=high){
        ll mid=(low+high)/2;
        if(check(mid,v,k,h)){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    h+=ans*sum;
    ans*=k;
    for(ll i=0;i<k;++i){
        if(h<=0) break;
        h+=v[i];
        ans++;
    }
    cout<<ans<<endl;
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

