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




 //morris traversal -->inorder --> tc(n) but no extra space unlike recursion stack space
 //left root right
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode *curr=root;
        while(curr!=NULL)
        {
        if(curr->left==NULL)
        {
            inorder.push_back(curr->val);
            curr=curr->right;
        }
        else
        //if left child exits
        {
            TreeNode *prev=curr->left;

            //we will go to the righmost child
                while(prev->right!=NULL && prev->right!=curr)
                prev=prev->right;


                //if the right child doesn't have any threaded link
                if(prev->right==NULL)
                {
                    //make the threaded connection
                    prev->right=curr;
                    //now move to the left of the curr to follow the same steps again
                    curr=curr->left;

                }

                //else if the threaded link is already present
                else if(prev->right==curr)
                {
                    //we need to imsert the curr in the inorder vector
                    inorder.push_back(curr->val);
                    //remove the threaded link otherwise the binary tree will be wrong
                    prev->right=NULL;

                    //move to the right now
                    curr=curr->right;
                }


        }
    }

        return inorder;
    }
};