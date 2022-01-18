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
    unordered_map<TreeNode*,int> mp;
    int rob(TreeNode* root) {
        // Add your code here
        /*We have 2 cases either we can include the current node or not include it,
          if we do include current node then we cannot include its children, else if we exclude the current node then we can include its childrens
          So we need maximum of both the cases
          
          Using just recursion will give us tle bcz we are computing a state many time,
          so we will use DP, we will just strore the answer of roots and if we have
          encountered current root before then we will just return its answer directly.
        */
        if(!root) return 0; //base case
        if(mp[root]) return mp[root];
        int inc=root->val; //includeing the current node
        if(root->left){
            inc+=rob(root->left->left);
            inc+=rob(root->left->right);
        }
        if(root->right){
            inc+=rob(root->right->left);
            inc+=rob(root->right->right);
        }
        
        int exc;
        exc=rob(root->left);
        exc+=rob(root->right);
        
        return mp[root]=max(inc,exc);
    }
};