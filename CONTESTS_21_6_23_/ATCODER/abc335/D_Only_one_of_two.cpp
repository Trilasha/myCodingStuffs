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
// B I N A R Y  S E A R C H - atleast think of its applicability once stupid





void solve(){
    ll a,b,k;
    cin>>a>>b>>k;
    ll l=lcm(a,b);
    ll lo=1;
    ll hi=1e18;
    ll ans=-1;
    while(lo<=hi){
        ll mid=(lo+hi)/2;
        ll cnt=mid/a+mid/b-2*(mid/l);
        if(cnt>=k){
            ans=mid;
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    cout<<ans<<endl;
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


int maxOperations(vector<int>& nums) {
        ll n=nums.size();
        vector<vector<ll>> dp(n+1,vector<ll>(n+1,-1LL));
        
        function<ll(ll,ll,ll)> recur=[&](ll i,ll j,ll sum){
            if(i>=j) return 0LL;
            if(dp[i][j]!=-1) return dp[i][j];
            ll ans=0;
            if((nums[i]+nums[j])==sum){
                ans=1+recur(i+1,j-1,sum);
            }
            if((i+1)<j && (nums[i]+nums[j])==sum){
                ans=max(ans,1+recur(i+1,j-1,sum));
            }
            if((j-1)>i && (nums[i]+nums[j])==sum){
                ans=max(ans,1+recur(i+1,j-1,sum));
            }
            return dp[i][j]=ans;
        };
        
        ll ans=max({recur(0,0,nums[0]+nums[1]),recur(n-1,n-2,nums[n-1]+nums[n-2]),recur(0,n-1,nums[0]+nums[n-1])});
        return ans;
    }



bool isPrime(ll n){
    if(n==1) return false;
    if(n==2 || n==3) return true;
    if(n%2==0 || n%3==0) return false;
    for(ll i=5;i*i<=n;i=i+6)
    if(n%i==0 || n%(i+2)==0)
    return false;
    return true;
}

vector<pll,char
void func(ll x,ll y,string s,vector<vector<ll>> &dp,vector<vector<int>> &mat){
    if(x<0 || y<0 || x>=n || y>=m || dp[x][y]) return;
    dp[x][y]=1;
    for(auto &i:dxy){
        ll xx=x+i.ff;
        ll yy=y+i.ss;
        if(xx>=0 && yy>=0 && xx<n && yy<m){
            ll val=mat[xx][yy];
            s+=char(val+'0');
            ll val=stoll(s);
            if(isPrime(val))mp[val]++;
            func(xx,yy,s,dp,mat);
        }
    }
}


//count number of words with a given prefix using trie
// to count the number of two strings such that s1 is both prefix and suffix of s2
// insert all the strings in the trie and then for each string s, count the number of prefixes of s in the trie

class TrieNode{
    public:
    TrieNode* next[26];
    ll prefix=0;
    bool isEnd;
};

class Trie{
    public:
    TrieNode* root;
    Trie(){
        root=new TrieNode();
    }
    void insert(string s){
        string temp=s;
        reverse(temp.begin(),temp.end());
        string t="";
        ll ind=s.size()-1;
        TrieNode* cur=root;
        for(ll i=0;i<s.size();++i){
            if(cur->next[s[i]-'a']==NULL){
                cur->next[s[i]-'a']=new TrieNode();
            }
            t+=temp[ind];
            revese(t.begin(),t.end());
            if(t==s.substr(0,i+1)){
                cur->prefix++;
            }
            revese(t.begin(),t.end());
            ind--;
            cur=cur->next[s[i]-'a'];
        }
        cur->isEnd=true;
    }
    ll countPrefix(string s){
        TrieNode* cur=root;
        for(auto &i:s){
            if(cur->next[i-'a']==NULL){
                return 0;
            }
            cur=cur->next[i-'a'];
        }
        return cur->prefix;
    }
    ll bothPrefixSuffix(string s){

    }
};



    long long countPrefixSuffixPairs(vector<string>& words) {
        ll n=words.size();
        Trie tr;
        ll ans=0;
        for(ll i=n-1;i>=0;--i){
            string s=words[i];
            string temp="";
            for(ll j=0;j<s.size();++j){
                temp+=s[j];
                ans+=tr.countPrefix(temp);
            }
            tr.insert(s);
        }
    }