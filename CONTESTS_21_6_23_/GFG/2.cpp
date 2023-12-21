class Solution {
  public:
    int solve(int N, string S) {
       set<int> st;
       for(auto &i:S)st.insert(i);
       return (st.size()-1);
    }
};