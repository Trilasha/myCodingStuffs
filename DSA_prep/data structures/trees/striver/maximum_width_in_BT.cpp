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


/*
Time Complexity: O(N)

Reason: We are doing a simple level order traversal. The inner loop simply traverses the nodes level-wise and doesn’t add to the complexity.

Space Complexity: O(N)
*/


///////////   DOUBT--> why else if creating a problem?
                    //why long long and
                    // the rightmost node index is 2^(height of tree-1) at any height check it yourself.... HOW???
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        if(root==NULL)
        return 0;

        queue<pair<TreeNode*,int>> q;
        int ans=0;

        q.push({root,0});

        while(!q.empty())
        {
            int size=q.size();
            int mini=q.front().second;
            int first_node;
            int last_node;
            for(int x=0;x<size;++x)
            {
                int curr_index=q.front().second-mini;
                TreeNode* curr_node=q.front().first;
                q.pop();

                if(x==0)
                first_node=curr_index;
                if(x==(size-1))
                last_node=curr_index;

                if(curr_node->left!=NULL)
                q.push({curr_node->left,(long long)2*curr_index+1});

                if(curr_node->right!=NULL)
                q.push({curr_node->right,(long long)2*curr_index+2});

            }

            ans=max(ans,last_node-first_node+1);
        }

        return ans;
    }
};