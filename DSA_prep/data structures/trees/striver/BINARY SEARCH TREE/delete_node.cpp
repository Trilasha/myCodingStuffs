//tc-->O(height of the tree)
//sc-->none




/*-------------------------------------------------------------------------------------------------------------------------------*/
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

    TreeNode* find_extreme_right(TreeNode* root)
    {
        if(root->right==NULL)
        return root;
        return find_extreme_right(root->right);
    }

    TreeNode* helper(TreeNode* root)
    {
        if(root->left==NULL)
            return root->right;

        else if(root->right==NULL)
            return root->left;

        TreeNode* curr_rightchild=root->right;
        TreeNode* extreme_rightnode=find_extreme_right(root->left);

        extreme_rightnode->right=curr_rightchild;

        return root->left;
        
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        //first need to find the node to be deleted
        //then upon finding it, a helper function will be called to make the new connections


        if(!root) return NULL;

        if(root->val==key)
        {
            root=helper(root);
            return root;
        }
        // to restore the original node value so that it can be returned at the end
        TreeNode *dummy=root;

        
        while(root!=NULL)
        {
            if(root->val==key)
            {
                root=helper(root);
                break;
            }
            else if(root->val>key)
            {
                if(root->left!=NULL && root->left->val==key)
                {
                root->left=helper(root->left);
                break;
                }
                else
                root=root->left;
            }
            else if(root->val<key)
            {
                if(root->right!=NULL && root->right->val==key)
                {
                root->right=helper(root->right);
                break;
                }
                else
                root=root->right;
            }
        }


        return dummy;

    }
};