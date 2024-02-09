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
    ll x=(n/2);
    if(n%2==0 && x%2){
        cout<<-1<<endl;
        return;
    }
    vector<vector<ll>> v(n,vector<ll>(n));
    if(n%2){
        ll a=1;
        ll x=0,y=0;
        ll odd=(n*n)/2 + 1;
        for(ll i=0;i<n;++i){
            v[0][i]=a;
            a+=2;
            odd--;
        }
        for(ll i=1;i<n;++i){
            v[i][0]=a;
            a+=2;
            odd--;
        }
        // cout<<odd<<endl;
        while(x<n){
            if(odd==0)break;
            x++;
            for(ll i=x+1;i<n;++i){
                if(odd==0)break;
                v[x][i]=a;
                a+=2;
                odd--;
                v[i][x]=a;
                a+=2;
                odd--;
            }
            if(odd==0)break;
        }
        a=2;
        for(ll i=0;i<n;++i){
            for(ll j=0;j<n;++j){
                if(v[i][j]==0){
                    v[i][j]=a;
                    a+=2;
                }
            }
        }
    }else{
        ll a=1;
        ll odd=(n*n)/2;
        ll col=0;
        while(1){
            if(odd==0)break;
            //cout<<odd<<endl;
            for(ll i=0;i<col+1;++i){
                if(odd==0)break;
                v[i][col]=a;
                a+=2;
                odd--;
            }
            col++;
        }
        a=2;
        for(ll i=0;i<n;++i){
            for(ll j=0;j<n;++j){
                if(v[i][j]==0){
                    v[i][j]=a;
                    a+=2;
                }
            }
        }

    }
    fr(i,n){
        fr(j,n){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
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

