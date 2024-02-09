/*
    When talent doesn't work hard then hardwork beats talent...
    ...hardwork always pays off
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
// insead of bpow use shift operators when b=2 to avoid tle 
// do not perform more than one optimal choice/ops in a single step/loop otherwise break your head with WA




vector<ll> big(vector <ll> &nums) {
    stack<pll> s;
    s.push({nums[0],0LL});
    ll n=nums.size();
    vector<ll> ans(n+1,-1);
    for (ll i = 1; i < n; i++) {
        if (s.empty()) {
            s.push({nums[i],i});
            continue;
        }
        while (s.empty() == false && s.top().ff < nums[i]) {
            ans[s.top().ss+1]=i+1;
            s.pop();
        }
        s.push({nums[i],i});
    }
    return ans;
}

vector<ll> small(vector<ll> &nums){
    stack<ll> st;
    ll n=nums.size();
    vector<ll> ans(n+1,-1);
    for (ll i = 0; i < n; ++i) {
        while (!st.empty() && nums[i] < nums[st.top()]) {
            ans[st.top()+1] = i+1;
            st.pop();
        }
        st.push(i);
    }
    return ans;
}
vector<ll> big2(vector<ll> &nums){
    stack<pll> s;
    s.push({nums[0],0});
    ll n=nums.size();
    vector<ll> ans(n+1,-1);
    for (int i = 1; i < n; i++) {
        while (s.empty() == false && s.top().ff <= nums[i]){
            s.pop();
        }
        s.empty() ? ans[i+1] = -1 : ans[i+1] = s.top().ss+1;
 
        s.push({nums[i],i});
    }
    return ans;
}
vector<ll> small2(vector<ll> &nums){
    stack<pll> st;
    ll n=nums.size();
    vector<ll> ans(n+1,-1);
    for (int i=0; i<n; i++){
        while (!st.empty() && st.top().ff >= nums[i])
            st.pop();
        if (st.empty())continue;
        ans[i+1] = st.top().ss+1;
        st.push({nums[i],i});
    }
    return ans;
}
void solve(){
    ll n;
    cin>>n;
    vector<ll> nums(n);
    inpv(nums);
    vector<ll> ng=big(nums);
    vector<ll> ng2=small(nums);
    vector<ll> revbig=big2(nums);
    vector<ll> revsmall=small2(nums);
    // printv(ng);printv(ng2);
    ll q;
    cin>>q;
    fr(i,q){
        ll l,r;
        cin>>l>>r;
        pll p=make_pair(-1,-1);
        if(ng[l]!=-1 && ng[l]<=r){
            p.ff=l;
            p.ss=ng[l];
            cout<<p.ff<<" "<<p.ss<<endl;
        }else if(ng2[l]!=-1 && ng2[l]<=r){
            p.ff=l;
            p.ss=ng2[l];
            cout<<p.ff<<" "<<p.ss<<endl;
        }else if(revbig[r]!=-1 && revbig[r]>=l){
            p.ff=revbig[r];
            p.ss=r;
            cout<<p.ff<<" "<<p.ss<<endl;
        }else if(revsmall[r]!=-1 && revsmall[r]>=l){
            p.ff=revsmall[r];
            p.ss=r;
            cout<<p.ff<<" "<<p.ss<<endl;
        }
        else{
            cout<<-1<<" "<<-1<<endl;
        }
    }
    cout<<endl;
 
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

