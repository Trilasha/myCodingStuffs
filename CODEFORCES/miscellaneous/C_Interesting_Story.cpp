//DEEPANSHU SONKAR
//2113092

#include<bits/stdc++.h>

#define turbo()                                                                \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0);

#define ll long long 
const ll mod=1000000007;
const ll INF= 1e9+7;
#define pb push_back
#define pp pop_back
#define mp make_pair
#define pf push_front
#define vll vector<ll>
#define get(a,n) vll a(n); for(int i=0;i<n;i++) cin>>a[i];
#define print(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl;
#define vsort(vec) sort(vec.begin(),vec.end());
#define rvsort(vec) sort(vec.begin(),vec.end(),greater<int>());
#define all(x) ((x).begin(),(x).end())
#define tc() long long int t;cin>>t;while(t--)
#define rep(var,start,to) for(ll var=start;var<to;var++)
#define rep1(a, b, c) for (ll a = b; a >= c; a--)
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define google cout<<"Case #"<<i+1<<": ";
 
 
 
 
using namespace std;
 
 
 
bool isprime(int n) {
  bool f = true;
  if (n == 0 || n == 1) {
    f = false;
  }
 
  for (int i = 2; i <= n / 2; ++i) {
    if (n % i == 0) {
      f = false;
      break;
    }
  }
 
  return f;
}


void codingkarlo_BC(){
  ll n;cin>>n;
  ll o=n;
  ll z=0;
  vector<string> v;
  map<char,ll> m;
  while(o--){
    string s;cin>>s;
    z+=s.length();
    v.push_back(s);
    rep(i,0,s.length()){
      m[s[i]]++;
    }
  }
  ll w=0;
  char key;
  for(auto i:m){
    w=max(w,i.second);
    if(i.second==w){
      key=i.first;
    }
  }

//cout<<w<<" "<<z-w<<endl;


  if(w>(z-w)){
    cout<<n<<endl;
  }
  else{
    ll y=abs(2*w-z);

    //cout<<y<<endl;

    vector<ll> v1;
    for(ll i=0;i<v.size();i++){
      ll cnt=0;
      for(ll j=0;j<v[i].length();j++){
        if(v[i][j]==key){
          cnt++;
        }
      }
      if(cnt<(v[i].length()-cnt)){
        v1.pb(abs(2*cnt-v[i].length()));
      }
    }
    sort(v1.begin(),v1.end(),greater<int>());
    ll final=0;
    ll anss=0;
    for(ll i=0;i<v1.size();i++){
      final+=v1[i];
      anss++;
      if(final>y){
        cout<<n-anss<<endl;
        return;
      }
    }
    if(v1.size()==0){
      cout<<0<<endl;
    }
    else{
      cout<<n-v1.size()-1<<endl;
    }

  }
    }
    
  
  
  
  



  
  
  

signed main()
{
    turbo()
   // codingkarlo_BC();
   tc(){ codingkarlo_BC(); /*google*/ }
   
 
 
    return 0;
}