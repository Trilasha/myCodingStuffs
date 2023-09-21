/*  
    Aisa Mera Dil Kabhi Na Tha
    Hairaan Be-Wajah
    Saughat Teri Hai Yeh...
        Bas Ek Baar Tumko... Dekhne Ko Tarsun...
        Kehta Hai Dil Yeh Mera... 
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







void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    inpv(v);
    vector<ll> temp;
    set<ll> st;
    for(ll i=0;i<=n+3;++i){
        st.insert(i);
    }
   
    for(ll i=0;i<n;++i){
        st.erase(st.find(v[i]));
    }

    temp.pb(*st.begin());
    st.erase(st.begin());
    st.insert(v[0]);
    
    for(ll i=1;i<n;++i){
        temp.pb(*st.begin());
        st.erase(st.begin());
        st.insert(v[i]);
    }

    temp.pb(*st.begin());
    // printv(temp);
    k--;
    ll pos=k%(n+1);
    if(pos==0){
        for(ll i=0;i<temp.size()-1;++i){
            cout<<temp[i]<<" ";
        }
        cout<<endl;
        return;
    }
    vector<ll> ans;
    ll bk=pos;
    //cout<<bk<<endl;
    while(bk>0){
        ans.pb(temp.back());
        temp.pop_back();
        bk--;
        if(ans.size()==n)break;
    }
    reverse(all(ans));
    for(ll i=0;i<temp.size();++i){
        if(ans.size()==n)break;
        ans.pb(temp[i]);
    }

    //cout<<"-----"<<endl;
    printv(ans);
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

