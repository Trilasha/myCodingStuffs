class Solution {
public:
    int bestClosingTime(string customers) {
        int sz=customers.size();
        int n=count(customers.begin(),customers.end(),'N');
        int y=count(customers.begin(),customers.end(),'Y');
        int curr_y=0;
        int curr_n=0;
        
        int index=-1;
        int curr_penalty=0;
        int penalty=INT_MAX;
        for(int i=0;i<sz;++i)
        {
            int rem_y=y-curr_y;
            curr_penalty=rem_y+curr_n;
            if(curr_penalty<penalty)
            {
                index=i;
                penalty=curr_penalty;
            }
            if(customers[i]=='Y')
                curr_y++;
            else
                curr_n++;
            
        }
        
        if(n<penalty)
            index=sz;
        
        return index;
    }
};