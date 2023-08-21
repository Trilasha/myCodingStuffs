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
    ll n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    vector<ll> days(m+1);
    vector<string> cure(m+1),disease(m+1);
    for(ll i=1;i<=m;++i){
        cin>>days[i]>>cure[i]>>disease[i];
    }
    vector<vector<ll>> v(n+1,vector<ll>(m+2,0));
    for(ll i=0;i<n;++i){
        for(ll j=1;j<=m;++j){
            if(cure[j][i]=='1')v[i][j]=1;
        }
    }
    priority_queue<pair<pair<ll,string>,ll>,vector<pair<pair<ll,string>,ll>>,greater<pair<pair<ll,string>,ll>>> pq;
    unordered_map<string,ll> mp;
    ll cnt=count(all(s),'0');
    pq.push({{0,s},cnt});

    while(!pq.empty()){
        ll tot_days=pq.top().ff.ff;
        string str=pq.top().ff.ss;
        ll zeroes=pq.top().ss;
        //cerr<<tot_days<<" "<<str<<endl;
        pq.pop();
        if(zeroes==n){
            cout<<tot_days<<endl;
            return;
        }
        if(mp[str])continue;
        mp[str]=1;

        for(ll i=0;i<n;++i){
            if(str[i]=='1'){
                for(ll k=1;k<=m;++k){
                    if(v[i][k]==1){
                    string temp=str;
                    ll cnt=0;
                    for(ll j=0;j<n;++j){
                        if(cure[k][j]=='1')temp[j]='0';
                        else if(disease[k][j]=='1')temp[j]='1';
                        if(temp[j]=='0')cnt++;
                    }
                    pq.push({{tot_days+days[k],temp},cnt});
                    }
                }
            }
        }
    }

    cout<<-1<<endl;
    
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



   
