//given n strings each of length m. Check if there is any pair of strings having exactly one character difference
//divide and conquer approach (recursion) --> tc(n*m*logm*logn)

bool recur(vector<string>&v){
    // debug(v);
    map<string,vector<string>>mp;
    ll sz=v[0].size();
    if(sz==1){
        set<char>st;
        for(auto x:v){
            st.insert(x[0]);
        }
        return st.size()>1;
    }
    rep(i,0,v.size()){
        string s=v[i];
        string s1=s.substr(0,sz/2);
        string s2=s.substr(sz/2);
        mp[s1].pb(s2);
    }
    ll ans=0;
    for(auto x:mp){
        if(x.S.size()>1){
            ans|=recur(x.S);
        }
    }
    mp.clear();
    rep(i,0,v.size()){
        string s=v[i];
        string s1=s.substr(0,sz/2);
        string s2=s.substr(sz/2);
        mp[s2].pb(s1);
    }
    for(auto x:mp){
        if(x.S.size()>1){
            ans|=recur(x.S);
        }
    }
    return ans;
}



void dk(){
    ll n,m;
    cin>>n>>m;
    vector<string>v(n);
    rep(i,0,n) cin>>v[i];
    cout<<(recur(v)?"YES":"NO")<<endl;
}