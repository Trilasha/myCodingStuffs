/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */



//meek//
/*----------------------------------------------------------------------------------------------------------------------------------*/
//tc--O(N);
//sc-->O(N);
class Solution {
public:
    void inorder_traversal(TreeNode *root,vector<int> &inorder)
    {
        if(root==NULL)return;
        inorder_traversal(root->left,inorder);
        inorder.push_back(root->val);
        inorder_traversal(root->right,inorder);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return NULL;
        vector<int> inorder;
        inorder_traversal(root,inorder);

        return inorder[k-1];
    }
};







/*----------------------------------------------------------------------------------------------------------------------------------*/
//tc->O(N)
//sc-> No extra space has been used
//morris traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=0;
    void inorder_traversal(TreeNode *root,vector<int> &inorder,int &cnt,int k)
    {
        if(root==NULL)return;
        inorder_traversal(root->left,inorder,cnt,k);
        cnt++;
        if(cnt==k)
        {
            ans=root->val;
        }
        inorder.push_back(root->val);
        inorder_traversal(root->right,inorder,cnt,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return NULL;
        vector<int> inorder;
        int cnt=0;
        inorder_traversal(root,inorder,cnt,k);

        return ans;
    }
};
