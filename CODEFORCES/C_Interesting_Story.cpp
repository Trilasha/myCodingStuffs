#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp> 


using namespace std;
//using namespace __gnu_pbds;
//typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds; 

           
#define ll                    long long
#define ld                    long double
#define pb                    push_back
#define popb                  pop_back
#define lb                    lower_bound
#define ub                    upper_bound
#define ff                    first
#define ss                    second
#define maxpq                 priority_queue <ll> pq;
#define minpq                 priority_queue <ll, vector<ll>, greater<ll> > pq; 
#define sp(x)                 fixed<<setprecision(x)
/// ---------------------------------------------------------------------------------------------------------- ///
#define md                    998244353
#define modval                1000000007
#define PI                    3.141592653589793238
#define bpl(n)                __builtin_popcountll(n);
/// ---------------------------------------------------------------------------------------------------------- ///
#define inp(n)                ll n;cin>>n;
#define inpv(v)               for(auto &x: v) cin>>x;
#define make(arr,n)           ll arr[n]; fr(i,n) cin>>arr[i];
/// ---------------------------------------------------------------------------------------------------------- ///
#define fr(i,n)               for (ll i=0;i<n;++i)
#define frs(i,k,n)            for(ll i=k;i<n;++i)
#define all(str)              str.begin(), str.end()
#define pll                   pair<ll,ll>
/// --------------------------------------------------------------------------------------------------------- ///
#define printv(v)             for(auto &i: v){cout << i << " ";} cout << endl;
#define printmap(mp)          for(auto &i: mp){cout << i.first << " "<<i.second<<endl;}
#define printset(st)          for(auto &i: st){cout << i << " ";} cout << endl;
#define line                  cout<<"----------------------------------------"<<endl;
#define arrow                 cout<<"--->";
#define debugmap(mp)             for(auto &i: mp){cout << i.ff << "-->" << i.ss <<endl;} cout << endl;
#define debugset(st)             for(auto &i: st){cout << i << " ";} cout << endl;
#define fast_io               ios_base::sync_with_stdio(false);cin.tie(NULL);

/// --------------------------------------------------------------------------------------------------------- ///
//reference for sequence(NT) --> oeis.org
//log2(x)
//give separate condition checks for smaller values of n(like n<=2)
//never use = sign in comparator functions
//the real challenge of bs --> selection of lo and hi




bool cmpa(pair<string,vector<ll>> &a,pair<string,vector<ll>> &b){
    if(a.ss[0]==b.ss[0])
    return a.ff.size()<b.ff.size();
    else
    return (a.ss[0]>b.ss[0]);
}
bool cmpb(pair<string,vector<ll>> &a,pair<string,vector<ll>> &b){
    if(a.ss[1]==b.ss[1])
    return a.ff.size()<b.ff.size();
    else
    return (a.ss[1]>b.ss[1]);
}
bool cmpc(pair<string,vector<ll>> &a,pair<string,vector<ll>> &b){
    if(a.ss[2]==b.ss[2])
    return a.ff.size()<b.ff.size();
    else
    return (a.ss[2]>b.ss[2]);
}
bool cmpd(pair<string,vector<ll>> &a,pair<string,vector<ll>> &b){
    if(a.ss[3]==b.ss[3])
    return a.ff.size()<b.ff.size();
    else
    return (a.ss[3]>b.ss[3]);
}
bool cmpe(pair<string,vector<ll>> &a,pair<string,vector<ll>> &b){
    if(a.ss[4]==b.ss[4])
    return a.ff.size()<b.ff.size();
    else
    return (a.ss[4]>b.ss[4]);
}

void solve(){
    ll n;
    cin>>n;
    vector<pair<string,vector<ll>>> vp;
    fr(i,n){
        string s;
        cin>>s;
        //sort(all(s));
        ll a=0,b=0,c=0,d=0,e=0;
        for(ll j=0;j<s.size();++j){
            if(s[j]=='a')a++;
            if(s[j]=='b')b++;
            if(s[j]=='c')c++;
            if(s[j]=='d')d++;
            if(s[j]=='e')e++;
        }
        vector<ll> temp={a,b,c,d,e};
        vp.pb({s,temp});
    }

    ll ans=0;
    ll curr=0;
    ll rem=0;
    ll cnt=0;

    //a
    sort(all(vp),cmpa);
    // for(auto &i:vp){
    // cout<<i.ff<<"-->"<<endl;
    // printv(i.ss);
    // }
    // line
    for(auto &i:vp){
        curr+=i.ss[0];
        rem+=i.ff.size()-i.ss[0];
        if(curr>rem)cnt++;
        else{
        curr-=i.ss[0];
        rem-=i.ff.size()-i.ss[0]; 
        }
    }
    ans=max(ans,cnt);
    cnt=0;
    curr=0;
    rem=0;
    //cout<<ans<<endl;

    sort(all(vp),cmpb);
    for(auto &i:vp){
        curr+=i.ss[1];
        rem+=i.ff.size()-i.ss[1];
        if(curr>rem)cnt++;
        else{
        curr-=i.ss[1];
        rem-=i.ff.size()-i.ss[1];
        }
    }
    ans=max(ans,cnt);
    cnt=0;
    curr=0;
    rem=0;
    //cout<<ans<<endl;

    sort(all(vp),cmpc);
    // for(auto &i:vp){
    // cout<<i.ff<<"-->"<<endl;
    // printv(i.ss);
    // }
    for(auto &i:vp){
        curr+=i.ss[2];
        rem+=i.ff.size()-i.ss[2];
        if(curr>rem)cnt++;
        else{
        curr-=i.ss[2];
        rem-=i.ff.size()-i.ss[2];
        }
    }
    ans=max(ans,cnt);
    cnt=0;
    curr=0;
    rem=0;
    //cout<<ans<<endl;

    sort(all(vp),cmpd);
    for(auto &i:vp){
        curr+=i.ss[3];
        rem+=i.ff.size()-i.ss[3];
        if(curr>rem)cnt++;
        else{
        curr-=i.ss[3];
        rem-=i.ff.size()-i.ss[3];
        }
    }
    ans=max(ans,cnt);
    cnt=0;
    curr=0;
    rem=0;
    //cout<<ans<<endl;

    sort(all(vp),cmpe);
    for(auto &i:vp){
        curr+=i.ss[4];
        rem+=i.ff.size()-i.ss[4];
        if(curr>rem)cnt++;
        else{
        curr-=i.ss[4];
        rem-=i.ff.size()-i.ss[4];
        }
    }
    ans=max(ans,cnt);
    
    cout<<ans<<endl;


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