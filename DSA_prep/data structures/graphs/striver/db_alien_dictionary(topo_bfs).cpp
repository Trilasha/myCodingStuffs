public:

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
when will there be no possible answer?

ex-1(if the larger string comes before the shorter string and everything else remains the same)
abcd
abc

ex-2(if any cyclic dependency is present)
abc
bat
ade
*/

//thus integrate these two checks also to make the code efficient 



//doubt?????????????
// 3 5
// abcd abc abce 

// why is the answer 0?
/////////////////////////////////////////////////////////////////////////////////////////////////////////

    vector<int> toposort(vector<vector<int>> &newAdj,int K)
    {
         vector<int> indegree(K,0);
        vector<int> topo;
	    for(auto &i:newAdj)
	    {
	        for(auto &j:i)
	        indegree[j]++;
	    }
	    
	    queue<int> q;
	    for(int i=0;i<K;++i)
	    {
	        if(indegree[i]==0)
	        q.push(i);
	    }
	
	
	    while(!q.empty())
	    {
	        int node=q.front();
	        q.pop();
	        topo.push_back(node);
	        for(auto &i:newAdj[node])
	        {
	            indegree[i]--;
	            if(indegree[i]==0)
	            q.push(i);
	        }
	    }
	    return topo;
    }
    
    
    
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<vector<int>> newAdj(K);
		int chk=0;
		set<char> st;
        for(int i=0;i<N-1;++i)
        {
            string s1=dict[i];
            string s2=dict[i+1];
            int len=min(s1.size(),s2.size());
			chk=0;
            for(int i=0;i<len;++i)
            {
                if(s1[i]!=s2[i])
                {
					chk=1;
                    newAdj[s1[i]-'a'].push_back(s2[i]-'a');
                    break;
                }
            }
			if(chk==0 && s1.size()>s2.size())
			{
				cout<<"Impossible"<<endl;
				return;
			}
        }
        
        vector<int> topo=toposort(newAdj,K);
       
	    string ans="";
	    for(int i=0;i<topo.size();++i)
	    {
	        ans.push_back('a'+topo[i]);
	    }
	    return ans;
    }