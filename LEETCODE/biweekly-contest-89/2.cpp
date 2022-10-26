class Solution {
public:
    #define ll long long
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        
        vector<long long> powers;
       // vector<int> powers;-->runtime error
        // cout<<pow(2,64);
        
         //long long nn=1e9+7;
          int nn=1e9+7;
        
        bitset<64> b(n);
        string s=b.to_string();
       // string s=to_string(bitset<64> b(n));-->wrong
        
        reverse(s.begin(),s.end());
        
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='1')
              //  powers.push_back(((long long)pow(2,(i)))%nn);
                powers.push_back(pow(2,i));
        }
        
       // sort(powers.begin(),powers.end());
        
        //ll anss=1;
        int anss=1;
        
        
        for(auto &i:queries)
        {
            anss=1;
            for(int j=i[0];j<=i[1];++j)
            {
               anss=(anss*powers[j])%(nn);
                //anss=anss*powers[i];-->wrong
              
            }
            ans.push_back(anss);
            //ans.push_back(anss%nn);-->wrong
        }
        
        return ans;
        //Line 20: Char 21: runtime error: signed integer overflow: 4194304 * 512 cannot be represented in type 'int' (solution.cpp)
//SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:29:21
    }
};