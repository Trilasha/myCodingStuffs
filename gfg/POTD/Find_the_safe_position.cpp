class Solution {
  public:
  void solve(vector<int> &v,int k,int index,int &ans)
  {
      if(v.size()==1)
      {
          ans=v[0];
          return;
      }
      index=(index+k)%v.size();
      v.erase(v.begin()+index);
      solve(v,k,index,ans);
      return;
  }
    int safePos(int n, int k) {
        // code here
        vector<int> v(n);
        for(int i=0;i<n;++i)
        v[i]=i+1;
        k--;
        int index=0;
        int ans=-1;
        solve(v,k,index,ans);
        return ans;
        
    }
};

//TC->O(n^2)