class Solution {
  public:
    //Function to return maximum path sum from any node in a tree.
    int max_path_sum(Node *root,int &res)
    {
    if(root==NULL)return 0;
    
    int left=max_path_sum(root->left,res);
    int right=max_path_sum(root->right,res);
    
    int temp=max((max(left,right)+root->data),root->data);
    int ans=max(temp,left+right+root->data);
    res=max(res,ans);
    
    return temp;
    }
    
    
    int findMaxSum(Node* root)
    {
        // Your code goes here
        int res=INT_MIN;
        max_path_sum(root,res);
        return res;
    }
};


/*
Time complexity: O(n) where n is the number of nodes
Auxiliary Space: O(1)
*/