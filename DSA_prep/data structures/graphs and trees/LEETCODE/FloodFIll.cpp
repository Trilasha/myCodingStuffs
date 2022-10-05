class Solution {
public:
    void dfs(int i,int j,vector<vector<int>> &image,int initialcolor,int color)
    {
        int n=image.size();
        int m=image[0].size();
        if(i<0 || j<0)
            return;
        if(i>=n || j>=m)
            return;
        if(image[i][j]!=initialcolor)return;
        image[i][j]=color;
         dfs(i-1,j,image,initialcolor,color);
         dfs(i+1,j,image,initialcolor,color);
         dfs(i,j-1,image,initialcolor,color);
         dfs(i,j+1,image,initialcolor,color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]!=color)
            dfs(sr,sc,image,image[sr][sc],color);
        return image;
    }
};


//Time complexity ->
//Space Complexity->