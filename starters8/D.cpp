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




int removeColon(string s)
{
    if (s.size() == 4) 
        s.replace(1, 1, "");
     
    if (s.size() == 5) 
        s.replace(2, 1, "");
     
    return stoi(s);
}
string diff(string s1, string s2)
{
 
    int time1 = removeColon(s1);
    int time2 = removeColon(s2);
  
    int hourDiff = time2 / 100 - time1 / 100 - 1;

    int minDiff = time2 % 100 + (60 - time1 % 100);
 
    if (minDiff >= 60) {
        hourDiff++;
        minDiff = minDiff - 60;
    }
  
    string res = to_string(hourDiff) + ':' + to_string(minDiff);
    return res;
}
string func(vector<string> &v,string &s){
    // for(int x=0;x<v.size();++x){
    //     if(v[x][0]=='0' && v[x][1]=='0') {
    //         v[x][0]='2';
    //         v[x][1]='4';
    //     }
    // }
    sort(v.begin(),v.end());
    string temp="";
    for(int x=0;x<v.size();++x){
        if(v[x]<s)continue;
        temp=v[x];
        break;
    }
    string ans=diff(s,temp);
    int ok1=0,ok2=0;
    int ind=-1;
    for(int x=0;x<ans.size();++x){
        if(ans[x]==':'){
            ind=x;
            break;
        }
        ok1++;
    }
    for(int x=ind+1;x<ans.size();++x){
        ok2++;
    }

    string ret="";
    if(ok1!=2 && ok2!=2){
        ret+='0';
        ret+=ans[0];
        ret+=':';
        ret+='0';
        ret+=ans[2];
    }else if(ok1!=2){
        ret+='0';
        ret+=ans[0];
        ret+=':';
        ret+=ans[2];
        ret+=ans[3];
    }else if(ok2!=2){
        ret+=ans[0];
        ret+=ans[1];
        ret+=':';
        ret+='0';
        ret+=ans[3];
    }else{
        ret+=ans.substr(0,2);
        ret+=':';
        ret+=ans.substr(3);
    }
    return ret;
}
void solve(){
    int n;
    cin>>n;
    vector<string> v(n);
    inpv(v);
    string s;
    cin>>s;
    cout<<func(v,s)<<endl;
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

class DSU{
    vector<ll> par,size;
public:
    ll tot_components;
    DSU(ll n){
        size.resize(n+1,1);
        par.resize(n+1);
        for(ll i=1;i<=n;++i)
        par[i]=i;
        tot_components=n;
    }
    ll findPar(ll node){
        if (node==par[node])
        return node;
        return par[node]=findPar(par[node]);
    }
    ll getsize(ll node){
        return size[findPar(node)];
    }
    void unite(ll u,ll v){
        ll ult_u=findPar(u);
        ll ult_v=findPar(v);
        if(ult_u==ult_v)return;
        if(size[ult_u]<size[ult_v]){
            size[ult_v]+=size[ult_u];
            par[ult_u]=ult_v;
        }else{
            size[ult_u]+=size[ult_v];
            par[ult_v]=ult_u;
        }
        tot_components--;
    }
};
 
