
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






string demo="codechef";
ll recur(ll ind,ll mask,string &s,string &temp,string &ans,vector<vector<ll>> &dp){
    if(ind==8){
        // cout<<"---->"<<endl;
        // cout<<mask<<endl;
        if(mask==((1<<8)-1)){
            ans=temp;
            return 1;
        }
        return 0;
    }
    if(dp[ind][mask]!=-1) return dp[ind][mask];
    // recur(ind+1,mask,s,temp,ans);
    ll ok=0;
    for(ll i=0;i<8;++i){
        if(mask&(1<<i) || s[i]==demo[ind])continue;
        temp+=s[i];
        ok|=recur(ind+1,mask|(1<<i),s,temp,ans,dp);
        temp.pop_back();
    }
    return dp[ind][mask]=ok;
    // return;
}
void solve(){
    string s;
    cin>>s;
    string ans="";
    vector<vector<ll>> dp(9,vector<ll>((1<<9),-1));
    string temp="";
    recur(0,0,s,temp,ans,dp);
    if(ans.size()==0){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
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

