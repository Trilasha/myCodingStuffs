/*
tc--> O(N)+O(NlogN)
sc--> O(N) + O(N) + O(N)
*/


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
    void mark_par(unordered_map<TreeNode*,TreeNode*> &parent,TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* current_node=q.front();
            q.pop();
            if(current_node->left!=NULL)
            {
                parent[current_node->left]=current_node;
                q.push(current_node->left);
            }
            if(current_node->right!=NULL)
            {
                parent[current_node->right]=current_node;
                q.push(current_node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root==NULL)return {};

        unordered_map<TreeNode*,TreeNode*> parent;
        mark_par(parent,root);

        queue<TreeNode*> q;
        int curr_dis=0;
        unordered_map<TreeNode*,int> visited(510);

        q.push(target);
        while(!q.empty())
        {
            int current_size=q.size();
            if(curr_dis==k)
            break;
            curr_dis++;

            for(int i=0;i<current_size;++i)
            {
                TreeNode *newnode=q.front();
                q.pop();
                visited[newnode]=1;

                if(newnode->left != NULL && !visited[newnode->left])
                {
                    visited[newnode->left]=1;
                    q.push(newnode->left);
                }
                 if(newnode->right != NULL && !visited[newnode->right])
                {
                    visited[newnode->right]=1;
                    q.push(newnode->right);
                }
                 if(parent[newnode]!=NULL && !visited[parent[newnode]])
                {
                    visited[parent[newnode]]=1;
                    q.push(parent[newnode]);
                }
            }

        }

        vector<int> req_nodes;

        while(!q.empty())
        {
            req_nodes.push_back(q.front()->val);
            q.pop();
        }

        return req_nodes;
    }
};