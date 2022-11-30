class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
    unordered_set<long long int> map;
    long long int left = 0, res = 0, sum = 0;
    for(long long int right = 0; right<nums.size(); right++)
    {
        while(left < right && (map.count(nums[right]) || map.size() >= k))
        //mp.size()==k will also work
        {
            sum -= nums[left];
            map.erase(nums[left]);
            left++;
        }
        sum +=nums[right];
        map.insert(nums[right]);
            
        if (map.size() == k)
            res = max(res, sum);
    }
    return res;
        
    }
};


/////////////////////////////////////////////////////// sliding window solution ////////////////////////////////////////////////////////
#define ll long long
class Solution {
public:
long long maximumSubarraySum(vector<int>& nums, int k) {
ll i = 0;
ll n = nums.size();
ll j = 0;
ll ans = -1;
ll sum = 0;
map<ll,ll> mp;
while(j < n) {
    mp[nums[j]]++;
    sum += nums[j];
    if(j - i + 1 < k) {
        j++;
    }
    else if(j - i + 1 == k) {
            if(mp.size() == k) {
                ans = max(ans, sum);
            }
        
        
            mp[nums[i]]--;
        //
        
            if(mp[nums[i]] == 0)
                mp.erase(nums[i]);
        
        
            sum -= nums[i];
            i++;
            j++;
    }
}
return (ans==-1)? 0: ans;
        
    }
};