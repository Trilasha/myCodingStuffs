//dfs--code1
//tc-->O(N*M)
//sc-->O(N*M)+O(N*M)  (2d matrix + recursion stack space)


public:
void dfs(int x,int y,int newcolor,vector<vector<int>> &image,int compcolor)
{
    int n=image.size();
    int m=image[0].size();
    if(x<0 || x>=n)return;
    if(y<0 || y>=m)return;
   // if(vis[x][y])return;
    if(image[x][y]!=compcolor)
    return;
   // vis[x][y]=1;
    image[x][y]=newcolor;
    dfs(x,y+1,newcolor,image,compcolor);
     dfs(x,y-1,newcolor,image,compcolor);
      dfs(x+1,y,newcolor,image,compcolor);
       dfs(x-1,y,newcolor,image,compcolor);
    
    
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int startx=sr;
        int starty=sc;
        int n=image.size();
        int m=image[0].size();
       // vector<vector<int>> vis(n,vector<int>(m,0));
        if(image[sr][sc]!=newColor)
        {
           // vis[sr][sc]=1;
            dfs(startx,starty,newColor,image,image[sr][sc]);
        }
        return image;
    }
};













//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//dfs-->code2
public:
void dfs(int x,int y,int newcolor,vector<vector<int>> &image,int compcolor)
{
    int n=image.size();
    int m=image[0].size();
    if(x<0 || x>=n)return;
    if(y<0 || y>=m)return;
   // if(vis[x][y])return;
    if(image[x][y]!=compcolor)
    return;
    if(image[x][y]==newcolor)
    return;
   // vis[x][y]=1;
    image[x][y]=newcolor;
    dfs(x,y+1,newcolor,image,compcolor);
     dfs(x,y-1,newcolor,image,compcolor);
      dfs(x+1,y,newcolor,image,compcolor);
       dfs(x-1,y,newcolor,image,compcolor);
    
    
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int startx=sr;
        int starty=sc;
        int n=image.size();
        int m=image[0].size();
       // vector<vector<int>> vis(n,vector<int>(m,0));
        // if(image[sr][sc]!=newColor)
        // {
           // vis[sr][sc]=1;
            dfs(startx,starty,newColor,image,image[sr][sc]);
        // }
        return image;
    }
};