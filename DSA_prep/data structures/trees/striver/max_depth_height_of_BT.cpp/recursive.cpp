/*
Time Complexity: O(N) 

Space Complexity: O(1) Extra Space + O(H) Recursion Stack space, where “H”  is the height of the binary tree.
*/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0; 
        
        int lh = maxDepth(root->left); 
        int rh = maxDepth(root->right); 
        
        return 1 + max(lh, rh); 
    }
};