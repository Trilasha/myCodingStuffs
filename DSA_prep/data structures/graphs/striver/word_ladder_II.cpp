public:

//time complexity cannot be predicted as it will vary from question to question

    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
      //  st.erase(beginWord);
        vector<string> usedOnlevel;
        int level=0;
        
        vector<vector<string>> ans;
        
        while(!q.empty())
        {
            vector<string> temp=q.front();
            q.pop();
            
            if(temp.size()>level)
            {
                level++;
                for(auto &i:usedOnlevel)
                st.erase(i);
                usedOnlevel.clear();
            }
            
            string word=temp.back();
            
            if(word==endWord)
            {
                if(ans.size()==0)
                ans.push_back(temp);
            else if(temp.size()==ans[0].size())
            ans.push_back(temp);
            }
            
            for(int i=0;i<word.size();++i)
            {
                char original=word[i];
                for(char c='a';c<='z';++c)
                {
                    word[i]=c;
                    if(st.find(word)!=st.end())
                    {
                        temp.push_back(word);
                        usedOnlevel.push_back(word);
                        q.push(temp);
                        temp.pop_back();
                    }
                }
                word[i]=original;
            }
        }
        return ans;
    }



///////////////////////////////////////////////////////////  another approach ////////////////////////////////////////////////////////////////
public:

//time complexity cannot be predicted as it will vary from question to question




    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
      //  st.erase(beginWord);-->wrong
        vector<string> usedOnlevel;
        // int level=0;
        int check=0;
        vector<vector<string>> ans;
        
        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
            vector<string> temp=q.front();
            q.pop();
            
            // if(temp.size()>level)
            // {
            //     level++;
            //     for(auto &i:usedOnlevel)
            //     st.erase(i);
            //     usedOnlevel.clear();
            // }
            
            string word=temp.back();
            
            if(word==endWord)
            {
              check=1;
              ans.push_back(temp);
            }
            
            for(int i=0;i<word.size();++i)
            {
                char original=word[i];
                for(char c='a';c<='z';++c)
                {
                    word[i]=c;
                    if(st.find(word)!=st.end())
                    {
                        temp.push_back(word);
                        usedOnlevel.push_back(word);
                        q.push(temp);
                        temp.pop_back();
                    }
                }
                word[i]=original;
            }
          }
          if(check)
          break;
          for(auto &i:usedOnlevel)
          st.erase(i);
          usedOnlevel.clear();
        }
        return ans;
    }