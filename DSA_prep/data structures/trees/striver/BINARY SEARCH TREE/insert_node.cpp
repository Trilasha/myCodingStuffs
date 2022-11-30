//meek//
//my recursive approach for this question
/*-----------------------------------------------------------------------------------------------------------------------------*/






//tc--> O(log2n) for a height balanced binary tree





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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
        {
            root=new TreeNode(val);
            return root;
        }

        if(root->left==NULL && root->val>val)
        {
        root->left=new TreeNode(val);
        }
        else if(root->right==NULL && root->val<val)
        {
            root->right=new TreeNode(val);
        }
        else if(root->val>=val)
        insertIntoBST(root->left,val);
        else if(root->val<val)
        insertIntoBST(root->right,val);

        return root;
    }
};







////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//iterative approach of striver
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        TreeNode *cur = root;
        while(true) {
            if(cur->val <= val) {
                if(cur->right != NULL) cur = cur->right;
                else {
                    cur->right = new TreeNode(val);
                    break;
                }
            } else {
                if(cur->left != NULL) cur = cur->left;
                else {
                    cur->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};