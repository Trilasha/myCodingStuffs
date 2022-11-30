class Solution:
    def gcd(a,b):
        if a == 0:
            return b
        return gcd(b % a, a)
 

    def lcm(a,b):
        return (a / gcd(a,b))* b
    
    def subarrayLCM(self, nums: List[int], k: int) -> int:
        ct=0
        ans=1
        for i in range(len(nums)):
            if(nums[i]==k):
                ct=ct+1
            ans=nums[i]
            for j in range(i+1,len(nums)):
                ans=lcm(ans,nums[j])
                if ans==k:
                    ct=ct+1
        return ct
        