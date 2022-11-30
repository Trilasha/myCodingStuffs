//meek
//tc-->O(N)
//sc-->O(N
/*------------------------------------------------------------------------------------------------------------------------------*/




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
    vector<int> inorder;
    void inorder_traversal(TreeNode* root)
    {
        if(!root) return;
        inorder_traversal(root->left);
        inorder.push_back(root->val);
        inorder_traversal(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        inorder_traversal(root);
        int i=0;
        int j=inorder.size()-1;

        while(i<j)
        {
            int sum=inorder[i]+inorder[j];
            if(sum==k)
            {
                return true;
            }
            else if(sum<k)
            i++;
            else 
            j--;
        }
        return false;
    }
};













/*------------------------------------------------------------------------------------------------------------------------------*/
//optimized approach using the BST operator 
//tc->O(N)
//sc-->2*O(H) equivalent to O(H)
/*------------------------------------------------------------------------------------------------------------------------------*/



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


class BSTiterator{
    stack<TreeNode*> myStack;
    bool curr_status=true;

    public:
    BSTiterator(TreeNode* root,bool status)
    {
        curr_status=status;
        pushAll(root);
    }

    int next()
    {
        TreeNode* temp = myStack.top();
        myStack.pop();

        if(curr_status==true)
        //after
        pushAll(temp->right);
        else
        pushAll(temp->left);

        return temp->val;
    }

    void pushAll(TreeNode *root)
    {
        while(root!=NULL)
        {
            myStack.push(root);
            if(curr_status==true)
             root=root->left;
             else
             root=root->right;
        }
    }

};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {

    //before will give the descending valued nodes
     BSTiterator before(root,false);
     //after will give the ascending valued nodes
     //(refer to the previous question)
     BSTiterator after(root,true);

     int i=after.next();
     int j=before.next();

     while(i<j)
     {
         if(i+j==k)return true;
         else if(i+j<k)
         i=after.next();
         else
         j=before.next();
     }

     return false;
    }
};




