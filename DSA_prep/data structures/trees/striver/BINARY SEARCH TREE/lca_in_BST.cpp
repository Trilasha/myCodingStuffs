//meek
//tc->O(H)
//sc->recursion stack space 
/*-------------------------------------------------------------------------------------------------------------------------------*/





/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p || root==q)
        return root;
        if((root->val>p->val && root->val<q->val) || (root->val>q->val && root->val<p->val))
        return root;
        if(root->val>p->val && root->val>q->val)
        return lowestCommonAncestor(root->left,p,q);
        else
        return lowestCommonAncestor(root->right,p,q);
    }
};









/*------------------------------------------------------------------------------------------------------------------------------*/
//striver's code
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        int curr = root->val; 
        if(curr < p->val && curr < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        if(curr > p->val && curr > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        return root;
    }
};