public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here

        //straight forward bfs has been used
        queue<pair<string,int>> q;
        q.push({startWord,1});
        unordered_set<string> st(wordList.begin(),wordList.end());
        st.erase(startWord);
        
        
        //tc--> N*wordlength*26*O(1)(if unordered_set)
        //tc-->N*wordlength*26*logn(if set)
        
        
        while(!q.empty())
        {
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();
            
            if(word==targetWord)
            return steps;
            
            for(int i=0;i<word.size();++i)
            {
                char ch=word[i];
                for(char c='a';c<='z';++c)
                {
                    word[i]=c;
                    if(st.find(word)!=st.end())
                    {
                        q.push({word,steps+1});
                        st.erase(word);
                    }
                    word[i]=ch;
                }
            }
        }
        return 0;
    }