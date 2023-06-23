class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        int n=creators.size();
       
        
        map<string,long long int> mp;
        for(int i=0;i<n;++i)
        {
            mp[creators[i]]+=views[i];
        }
        
        
        
        
        map<string,int> mp2;
        for(int i=0;i<n;++i)
        { 
            mp2[creators[i]]=-1;
        }
        for(int i=0;i<n;++i)
        {
            if(mp2[creators[i]]==-1)
            {
                mp2[creators[i]]=i;
            }
            else if(views[i]>views[mp2[creators[i]]])
                  mp2[creators[i]]=i;
            else if(views[i]==views[mp2[creators[i]]] && ids[i]<ids[mp2[creators[i]]])
                mp2[creators[i]]=i;
        }
        
        
        
        vector<vector<string>> final;
        
        
        
        long long int maxy=-1;
        for(auto &i:mp)
        {
            if(i.second>maxy)
                maxy=i.second;
        }
        
        
       //cout<<mp.size();
       for(auto &i:mp)
        {
           vector<string> temp;
            if(i.second==maxy)
            {
                temp.push_back(i.first);
                temp.push_back(ids[mp2[i.first]]);
                 final.push_back(temp);
            }
        }
        return final;
    }
};
