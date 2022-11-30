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
    bool validate(TreeNode* root,long long min_val,long long max_val)
    {
        if(root==NULL) return true;
        if(root->val>=max_val || root->val<=min_val)return false;
        return (validate(root->left,min_val,root->val) && validate(root->right,root->val,max_val));
    }

    bool isValidBST(TreeNode* root) {
        return validate(root,LLONG_MIN,LLONG_MAX);
    }
};