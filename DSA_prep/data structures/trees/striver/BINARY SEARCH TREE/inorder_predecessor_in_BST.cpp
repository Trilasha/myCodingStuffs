//tc-->O(H)
//sc-->O(1)

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* predecessor = NULL;
        
        while (root != NULL) {
            
            if (p->val > root->val) {
                predecessor=root;
                root=root->right;
            } else {
                root = root->left;
            }
        }
        
        return predecessor;
    }
};