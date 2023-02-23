
class Solution{
    public:
    
    int max_path_sum(Node *root)
    {
        if(root==NULL)return 0;
        
        int left=max_path_sum(root->left);
        int right=max_path_sum(root->right);
        
        int temp;
        if(root->left!=NULL && root->right!=NULL)
        temp=max(left,right)+root->data;
        else if(root->left!=NULL)
        temp=left+root->data;
        else if(root->right!=NULL)
        temp=right+root->data;
        else
        temp=root->data;
        
        
        return temp;
    }
    int maxPathSum(Node* root)
    {
        //code here
        return max_path_sum(root);
    }
};



/*
Time Complexity : O(N) as we are only traversing the whole tree.
Space complexity : O(1) as we are not using any extra data structures where recursion call stack is ignored.  If recursion call stack is considered, then its space complexity is O(h) where h is the height of the tree. Here Space Complexity is not O(N) because recursion call stack is reused for different calls. 
*/