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
    ll n,p,q;
    cin>>n>>p>>q;
    vector<ll> v(n);
    inpv(v);
    ll curr=n;
    set<ll> st(v.begin(),v.end());
    map<ll,ll> mp;
    for(auto &i:v){
        mp[i]++;
    }


    while(q>0 && curr>0){
        auto it=st.begin();
        ll f1=*it;
        it=prev(st.end());
        ll f2=*it;
        if(f1<0  && f2>0){
            mp[f1]--;
            mp[f2]--;
            if(mp[f1]<=0){
                st.erase(f1);
            }
            if(mp[f2]<=0){
                st.erase(f2);
            }
            mp[f2-f1]++;
            st.insert(f2-f1);
            q--;
            curr--;
        }else{
            break;
        }
    }
    while(curr>1 && p>0){
        //for +
        auto it=st.begin();
        ll f1=*it;
        ll f2=0;
        if(mp[*it]>1){
            f2=*it;
        }else{
            it++;
            if(it==st.end())break;
            f2=*it;
        }

        it=prev(st.end());
        ll l1=*it;
        ll l2=0;
        if(mp[*it]>1){
            l2=*it;
        }else{
            if(st.size()==1)break;
            it--;
            l2=*it;
        }
        
        if(p>0){
            if((f1<0 && f2<0) && (l1>0 && l2>0)){
                ll add=abs(f1)+abs(f2)+l2;
                ll add2=l1+l2-(f1);
                if(add2>=add){
                    mp[l1]--;
                    mp[l2]--;
                    if(mp[l1]<=0){
                        st.erase(l1);
                    }
                    if(mp[l2]<=0){
                        st.erase(l2);
                    }
                    mp[l1+l2]++;
                    st.insert(l1+l2);
                }else{
                    mp[f1]--;
                    mp[f2]--;
                    if(mp[f2]<=0){
                        st.erase(f1);
                    }
                    if(mp[f2]<=0){
                        st.erase(f2);
                    }
                    mp[f1+f2]++;
                    st.insert(f1+f2);
                }
                p--;
                curr--;
            }else if(f1<0 && f2<0){
                
                    mp[f1]--;
                    mp[f2]--;
                    if(mp[f2]<=0){
                        st.erase(f1);
                    }
                    if(mp[f2]<=0){
                        st.erase(f2);
                    }
                    mp[f1+f2]++;
                    st.insert(f1+f2);
                    p--;
                    curr--;
            }else if(l1>0 && l2>0){
                    mp[l1]--;
                    mp[l2]--;
                    if(mp[l1]<=0){
                        st.erase(l1);
                    }
                    if(mp[l2]<=0){
                        st.erase(l2);
                    }
                    mp[l1+l2]++;
                    st.insert(l1+l2);
                    p--;
                    curr--;
            }
        }
        
    }

    cout<<(*st.rbegin())-(*st.begin())<<endl;
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

