/*

*.....
..*...
.****.
..*...
..*...


It's similar to what you said check in all 4 directions if there is a star, then traverse each of the 4 directions till you have a star. Then you can either:
1. change * to .
2. maintain a bool matrix and check if other stars are left
3. compare total stars with stars in +

*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int r,c;
    cin>>r>>c;
    vector<vector<char>> v;
   for(int i=0;i<r;++i)
   {
    for(int j=0;j<c;++j)
    {
        cin>>v[i][j];
    }
   }

   vector<vector<int>> vis(r,vector<int>(c,0));

   int ct=0;
   int chk=0;
   for(int i=0;i<r;++i)
   {
    for(int j=0;j<c;++j)
    {
        if(v[i][j]=='*')
        {
            ans++;
            vis[i][j]=1;
            
        }
    }
   }
    return 0;
}
