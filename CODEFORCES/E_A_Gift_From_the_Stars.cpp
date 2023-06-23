class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int last=-1;
        set<string> st;
        int n=dictionary.size();
        for(int i=0;i<n;++i){
            st.insert(dictionary[i]);
        }
        
        int nn=s.size();
        for(int i=0;i<nn;++i){
            string temp="";
            temp+=s[i];
            int ok=0;
            if(st.find(temp)!=st.end()){
                last=max(last,i);
                ok=1;
            }
            for(int j=i+1;j<nn;++j){
                temp+=s[j];
                if(st.find(temp)!=st.end()){
                last=max(last,j);
                 ok=1;
            }
            }
                if(ok==0){
                    if(last<i)
                      s[i]='*';
            }
        }
        
        int ans=0;
        for(int i=0;i<nn;++i){
            if(s[i]=='*')ans++;
        }
        return ans;
        
    }
    
    
    /*
    Input:
"voctvochpgutoywpnafylzelqsnzsbandjcqdciyoefi"
["tf","v","wadrya","a","cqdci","uqfg","voc","zelqsn","band","b","yoefi","utoywp","herqqn","umra","frfuyj","vczatj","sdww"]
Output:
13
Expected:
11

Input:
"kevlplxozaizdhxoimmraiakbak"
["yv","bmab","hv","bnsll","mra","jjqf","g","aiyzi","ip","pfctr","flr","ybbcl","biu","ke","lpl","iak","pirua","ilhqd","zdhx","fux","xaw","pdfvt","xf","t","wq","r","cgmud","aokas","xv","jf","cyys","wcaz","rvegf","ysg","xo","uwb","lw","okgk","vbmi","v","mvo","fxyx","ad","e"]
Output:
8
Expected:
9



    */
};