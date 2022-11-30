//brute force method--> O(NlogN)





//optimized
//tc--> O(N)
//sc-->O(1)
//for even better sc, we can go with morris traversal





//Why is the other code throwing runtime error????





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
    TreeNode* first=NULL;
    TreeNode* mid=NULL;
    TreeNode* final=NULL;
    TreeNode* prev=NULL;
    void inorder(TreeNode* root)
    {
        if(root==NULL)return;
        inorder(root->left);

        if(prev!=NULL && (root->val<prev->val))
        {
            if(first==NULL)
            {
                first=prev;
                mid=root;
            }
            else
                final=root;
        }

        prev=root;
        inorder(root->right);
        
    }
    void recoverTree(TreeNode* root) {
        inorder(root);

        if(final!=NULL)
        swap(first->val,final->val);
        else 
        swap(first->val,mid->val);
    }
};