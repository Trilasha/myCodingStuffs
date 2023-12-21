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
    ll n;
    cin>>n;
    string s;
    cin>>s;
    if(n==1){
        cout<<'8'<<endl;
        return;
    }
    if(n==2){
        ll val=stoll(s);
        if(val%8==0){
            cout<<s<<endl;
        }else{
            if(s[0]=='1'){
                cout<<"16"<<endl;
            }else if(s[0]=='2'){
                cout<<24<<endl;
            }else if(s[0]=='3'){
                cout<<32<<endl;
            }else if(s[0]=='4'){
                cout<<48<<endl;
            }else if(s[0]=='5'){
                cout<<56<<endl;
            }else if(s[0]=='6'){
                cout<<64<<endl;
            }else if(s[0]=='7'){
                cout<<72<<endl;
            }else if(s[0]=='8'){
                cout<<80<<endl;
            }else if(s[0]=='9'){
                cout<<96<<endl;
            }
        }
        return;
    }
    string var="";
    var+=s[n-3];
    var+=s[n-2];
    var+=s[n-1];
    ll ans=3;
    string add="",temp="";
    for(ll i=0;i<=9;++i){
        for(ll j=0;j<=9;++j){
            for(ll k=0;k<=9;++k){
                temp="";
                temp+=char(i+'0');
                temp+=char(j+'0');
                temp+=char(k+'0');
                ll val=stoll(temp);
                if(val%8==0){
                    //cout<<temp<<endl;
                    ll ok=0;
                    if(var[0]!=temp[0])ok++;
                    if(var[1]!=temp[1])ok++;
                    if(var[2]!=temp[2])ok++;
                    if(ok<=ans){
                        ans=ok;
                        add=temp;
                    }
                }
            }
        }
    }
    s[n-3]=add[0];
    s[n-2]=add[1];
    s[n-1]=add[2];
    cout<<s<<endl;
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

