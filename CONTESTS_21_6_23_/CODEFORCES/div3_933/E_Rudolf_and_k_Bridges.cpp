/*
    Trilasha Mazumder
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





void solve(){
    ll n,m,k,d;
    cin>>n>>m>>k>>d;
    vector<vector<ll>> v(n,vector<ll>(m));
    fr(i,n){
        fr(j,m){
            cin>>v[i][j];
        }
    }
    vector<ll> pref(n+2);
    for(ll row=0;row<n;++row){
        // ll cost=2;
        // ll i=0,j=m-1;
        // while(i<j){
        //     if((i+d+1)>=j)break;
        //     if((i+d+1)<((j-d-1))){
        //         cost+=v[row][i+d+1]+v[row][j-d-1]+2;
        //         i+=d+1;
        //         j-=d;
        //         j--;
        //     }else{
        //         ll mn=min(v[row][i+d+1],v[row][j-d-1]);
        //         cost+=mn+1;
        //         break;
        //     }
        // }
        vector<ll> temp(m+1,1e18);
        temp[0]=0;
        deque<ll> dq;
        dq.push_back(0);
        temp[0]=1;
        for(ll j=1;j<m;++j){
            while(!dq.empty() && (j-d-1)>dq.front())dq.pop_front();
            if(!dq.empty())temp[j]=temp[dq.front()]+v[row][j]+1;
            while(!dq.empty() && temp[j]<=temp[dq.back()])dq.pop_back();
            dq.push_back(j);
        }
        pref[row+1]=temp[m-1];
    }
    // cout<<pref[1]<<endl;
    for(ll i=2;i<=n;++i){
        pref[i]+=pref[i-1];
        // cout<<pref[i]<<endl;
    }
    ll ans=pref[k];
    for(ll i=k+1;i<=n;++i){
        ans=min(ans,pref[i]-pref[i-k]);
    }
    cout<<ans<<endl;
 
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

