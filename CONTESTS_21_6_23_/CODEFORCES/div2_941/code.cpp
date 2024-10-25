 map<char,int> mp1,mp2,mp3,mp4;
        mp[grid[0][0]]++;
        mp[grid[0][1]]++;
        mp[grid[1][0]]++;
        mp[grid[1][1]]++;
        if(mp['B']>=3 || mp['W']>=3) return true;

// same for the other 3 corners
// Path: code.cpp
 map<char,int> mp1,mp2,mp3,mp4;
        mp[grid[0][0]]++;
        mp[grid[0][1]]++;
        mp[grid[1][0]]++;
        mp[grid[1][1]]++;
        if(mp['B']>=3 || mp['W']>=3) return true;


//given the grid of 0 and 1 

vector<vector<ll>> row(n+1,vector<ll>(m+1,0)),col(m+1,vector<ll>(n+1));
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++){
                row[i][j]=row[i][j-1]+grid[i-1][j-1];
            }
        }
        for(ll i=1;i<=m;i++){
            for(ll j=1;j<=n;j++){
                col[i][j]=col[i][j-1]+grid[j-1][i-1];
            }
        }
        for(ll i=1;i<=n;++i){
            for(ll j=1;j<=m;++j){
                ll cnt=0;
                if(grid[i-1][j-1]==1){
                    //count of ones right
                    ll r=row[i][m]-row[i][j];
                    //count of ones to the bottom
                    ll b=col[j][n]-col[j][i];
                    cnt+=r*b;
                    //count left of the current cell
                    ll w=row[i][j-1];
                    cnt+=w*b;
                    //count above the current cell
                    ll t=col[j][i-1];
                    cnt+=t*r;
                    cnt+=t*w;
                    ans+=cnt;

                }
            }
        }

        bitset<32> b=n-1;
        string s=b.to_string();