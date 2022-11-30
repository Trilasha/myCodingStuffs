class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        
        
        int sum=0;
        int temp=0;
        
        for(int i=0;i<k;++i)
        {
            temp+=nums[i];
            mp[nums[i]]++;
        }
        
        int chk=0;
        
        for(auto &i:mp)
        {
            if(i.second>1)
            {
                chk=1;
                break;
            }
        }
        
        if(chk==0)
            sum+=temp;
        
        
        temp=0;
        cout<<sum<<endl;
        int index=0;
        int ct=k-1;
        int cot=0;
        
        int chk2=0;
        int temp_sum=0;
        int ts=0;
        int tts=sum;
      //  int temp=0;
        
        for(int i=k;i<nums.size();++i)
        {
            temp+=nums[i];
            
            if(chk==0)
            ts+=nums[index];
            
            cout<<temp<<" "<<ts<<endl;
            mp[nums[index]]--;
            
            if(mp[nums[i]]==0 && chk2==0)
                ct++;
            
            
            
            
            if(mp[nums[i]]==0 && ct==k)
            {
               // cot++;
                cout<<"aa"<<endl;
                temp_sum=sum-ts+temp;
                cout<<temp_sum<<endl;
                if(temp_sum>sum)
                {
                    //ct=k-1;
                sum=temp_sum;
                ts-=nums[index];
               // temp=0;
                }
              //  ct=k-1;
                temp=0;
                mp[nums[i]]=1;
                //index++;
                // mp[nums[i]]++;
                
            }
            
            
            
            
            else if(mp[nums[i]]!=0 && chk2==0)
            {
              // i=i-1;
                ct=1;
                chk2=1;
                temp=nums[i];
                ts=nums[i];
            }
            
            
            if(chk2==0)
                ct=k-1;
            else if(mp[nums[i]]==0 && chk2==1)
            {
                cout<<"ll"<<endl;
                ct++;
                mp[nums[i]]=1;
                if(ct==k)
                {
                    cout<<"ll2"<<endl;
                    ct=k-1;
                    chk2=0;
                    temp_sum=sum-ts+temp;
                    if(temp_sum>sum)
                    {
                        sum=temp_sum;
                    }
                  // temp=0;
                }
            }
            
            //chk2=1;
            index++;
            cout<<sum<<endl;
            cout<<"------"<<endl;
        }
        
        
        
        
//         unordered_set<long long int> map;
//     long long int left = 0, res = 0, sum = 0;
//     for(long long int right = 0; right<nums.size(); right++)
//     {
//         while(left < right && (map.count(nums[right]) || map.size() >= k))
//         {
//             sum -= nums[left];
//             map.erase(nums[left]);
//             left++;
//         }
//         sum +=nums[right];
//         map.insert(nums[right]);
            
//         if (map.size() == k)
//             res = max(res, sum);
//     }
//     return res;
        
            return sum;
        
    }
};