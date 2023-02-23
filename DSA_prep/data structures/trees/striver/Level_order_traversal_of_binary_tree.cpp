/*
Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> ans; 
        
        if(root == NULL) 
            return ans; 
            
        queue<TreeNode*> q; 
        q.push(root); 
        
        while(!q.empty()) {
           
            TreeNode *temp = q.front(); 
            q.pop(); 
            
            if(temp->left != NULL) 
                q.push(temp->left); 
            if(temp->right != NULL) 
                q.push(temp->right); 
                
            ans.push_back(temp->val); 
        }
        return ans; 
    }
};





void level_order_traversal(Node* root,vector<int> &inorder)
{
    if(root==NULL)
    return {};

    queue<Node* > queue1;
    queue1.push(root);

    while(!queue1.empty())
    {
        Node* curr_node=queue1.front();
        inorder.push_back(curr_node->val);
        queue1.pop();

        if(curr_node->left)
        queue1.push(curr_node->left);
        if(curr_node->right)
        queue1.push(curr_node->right);

    }


}