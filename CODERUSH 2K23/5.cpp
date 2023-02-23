//to be understood


//way1
#include <bits/stdc++.h>
  using namespace std;
  #define ll long long

long long subArrayRanges(vector<ll>& nums) {
      int n = nums.size();
      long long answer = 0;
      stack<ll> st;
      
      // Find the sum of all the minimum.
      for (int right = 0; right <= n; ++right) {
          while (!st.empty() && (right == n || nums[st.top()] >= nums[right])) {
              ll mid = st.top();
              st.pop();
              ll left = st.empty() ? -1 : st.top();
              answer -= (long long)nums[mid] * (right - mid) * (mid - left);
          }
          st.push(right); 
      }
      
      // Find the sum of all the maximum.
      st.pop();
      for (int right = 0; right <= n; ++right) {
          while (!st.empty() && (right == n || nums[st.top()] <= nums[right])) {
              ll mid = st.top();
              st.pop();
              ll left = st.empty() ? -1 : st.top();
              answer += (long long)nums[mid] * (right - mid) * (mid - left);
          }
          st.push(right); 
      }
      return answer;
  }
  int main() {

    int n; cin >> n;
    vector<ll> v(n);  
    for (int i=0; i<n; i++) {
      cin >> v[i]; 
    }
    cout << subArrayRanges(v); 

  }









/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
