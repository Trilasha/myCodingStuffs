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

//tc of swapping --> nlogn
void swap(vector<int> &arr, int i, int j){
        int temp;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    int min_Swaps(vector<int> arr){
        int n = arr.size();
        int ans = 0;
        unordered_map<int, int> mp;
        for (int i=0 ; i<n ; i++){
            mp[arr[i]] = i;
        }
        
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        
        for (int i=0 ; i<n ; i++){
            if (arr[i] != temp[i]){
                ans++;
                int init = arr[i];
                swap(arr, i, mp[temp[i]]);
                mp[init] = mp[temp[i]];
                mp[temp[i]] = i;
            }
        }
        return ans;
    }

    int minimumOperations(TreeNode* root) {
        if(root==NULL)
            return 0;
        queue<TreeNode*> q;
        
        q.push(root);
        int ans=0;
        
        while(!q.empty())
        {
            int n=q.size();
            vector<int> v;
           for(int i=0;i<n;++i)
           {
               TreeNode* node=q.front();
               v.push_back(node->val);
               q.pop();
               if(node->left!=NULL)
                   q.push(node->left);
               if(node->right!=NULL)
                   q.push(node->right);
           }
            ans+=min_Swaps(v);
             // cout<<ans<<endl;
        }
        return ans;
    }
};