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
   vector<vector<ll>> v(n,vector<ll>(n,-1));
   if(n%2){
    ll odd=1,even=2;
    ll fillodd=0;
    ll chk=0;
    for(ll i=0;i<n;++i){
            if(fillodd==(n-1)/2){
                chk=1;
            }
            ll mid=n/2;
            v[i][mid]=odd;
            odd+=2;
            ll k=mid-1;
            ll itr=fillodd;
            while(itr){
                v[i][k]=odd;
                odd+=2;
                k--;
                itr--;
            }
            itr=fillodd;
            k=mid+1;
            while(itr){
                v[i][k]=odd;
                odd+=2;
                k++;
                itr--;
            }
            if(chk==0)
                fillodd++;
            else if(chk==1){
                fillodd--;;
            }
            if(odd>n*n)break;
    }
    for(ll i=0;i<n;++i){
            for(ll j=0;j<n;++j){
                if(v[i][j]==-1){
                    v[i][j]=even;
                    even+=2;
                }
            }
    }
   }


   else{
    ll filleven=n-1;
    ll odd=1,even=2;
    for(ll i=0;i<n/2;++i){
        ll itr=filleven;
        ll k=0;
        ll col=i;
        while(itr){
            v[k][col]=odd;
            odd+=2;
            k++;
            itr--;
        }
        col=n-i-1;
        k=n-1;
        itr=filleven;
        while(itr){
            v[k][col]=odd;
            odd+=2;
            k--;
            itr--;
        }
        filleven-=2;
    }
    for(ll i=0;i<n;++i){
        for(ll j=0;j<n;++j){
            if(v[i][j]==-1){
                v[i][j]=even;
                even+=2;
            }
        }
    }
   }
    for(ll i=0;i<n;++i){
        for(ll j=0;j<n;++j){
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

