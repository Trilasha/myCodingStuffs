class LUPrefix {
    private:
    deque<int> dq;
    int last=0;
public:
    LUPrefix(int n) {
        dq.assign(n,0);
    }
    
    void upload(int video) {
        dq[video-last-1]=1;
        while(dq.front()==1)
        {
            dq.pop_front();
            last++;
        }
    }
    
    int longest() {
        return last;
    }
};


////////////////////////////   ANOTHER APPROACH   ///////////////////////////////
class LUPrefix {
    // private:
    deque<int> dq;
    int last=0;
public:
    LUPrefix(int n) {
        dq.assign(n,0);
    }
    
    void upload(int video) {
        dq[video-last-1]=1;
        while(dq.front()==1)
        {
            dq.pop_front();
            last++;
        }
    }
    
    int longest() {
        return last;
    }
};



///////////////////////////////  ANOTHER ONE APPROACH  //////////////////////////////////
class LUPrefix {
public:
    vector<int> v;
    int ans=0;
    LUPrefix(int n) {
        v.assign(n+2,0);
    }
    
    void upload(int video) {
        v[video-1]=1;
    }
    
    int longest() {
        while(v[ans])
            ans++;
         return ans;
    }
   
};


/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */