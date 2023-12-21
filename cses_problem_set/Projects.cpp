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
#define pii                   pair<int,int>
//#define endl                " \n"
/*----------------------------------------------------------------------------------------------------------- */




int findNext(int ind,vector<pair<pii,int>> &vp){
        int low=ind+1;
        int high=vp.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(vp[mid].first.first>vp[ind].first.second){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }

ll recur(int ind,vector<pair<pii,int>> &vp,vector<ll> &dp){
    if(ind>=vp.size()) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int nextEventInd=findNext(ind,vp);
    ll np=recur(ind+1,vp,dp);
    ll p=vp[ind].second + ((nextEventInd==-1)?0:recur(nextEventInd,vp,dp));
    return dp[ind]=max(p,np);
}

void solve(){
    int n;
    cin>>n;
    vector<pair<pii,int>> vp(n);
    for(int x=0;x<n;++x){
        int a,b,c;
        cin>>a>>b>>c;
        vp[x].first.first=a;
        vp[x].first.second=b;
        vp[x].second=c;
    }
    sort(vp.begin(),vp.end());
    vector<ll> dp(n+1,-1);
    cout<<recur(0,vp,dp)<<endl;
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

