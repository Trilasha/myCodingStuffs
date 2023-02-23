//not understood


#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define endl                "\n"
#define read(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end() 
#define fast_io             ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io             freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define int                 long long
#define ld                  long double
#define printv(v)           for(int i=0;i<v.size();i++){cout<<v[i]<<" ";}cout<<endl; 
void google(int t)          {cout << "Case #" << t << ": ";}

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // *find_by_order, order_of_key
int bpow(int base,int power){int res=1;while(power){if(power&1){res *= base;power--;}else{base *= base;power /=2;}}return res;}






void solve(){

   int n,m;
   cin>>n>>m;

   string str;
   cin>>str;

   
   map<int,set<int>>mp;
   vector<pair<int,int>>vp;
   for(int i=0;i<n;i++){
     int x,y;
     cin>>x>>y;
     vp.push_back({x+y,y-x});
     mp[vp[i].first].insert(vp[i].second);
     mp[vp[i].second].insert(vp[i].first);
   }

   int x = vp[0].first;
   int y = vp[0].second;

   for(int i=0;i<m;i++){
        mp[y].erase(x);
        mp[x].erase(y);
      if(str[i]=='A'){
          auto it = mp[y].upper_bound(x);
          if(it==mp[y].end()){continue;}
           x = *it;
      }else if(str[i]=='D'){
          auto it = mp[y].upper_bound(x);
          if(it==mp[y].begin())continue;
          it--;
           x = *it;
      }else if(str[i]=='B'){
          auto it = mp[x].upper_bound(y);
          if(it==mp[x].begin())continue;
          it--;
          y = *it;
      }else{
          auto it = mp[x].upper_bound(y);
          if(it==mp[x].end())continue;
           y = *it;
      }
   }