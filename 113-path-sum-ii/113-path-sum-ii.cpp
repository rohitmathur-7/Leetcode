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
    vector<vector<int>> ans;
    
    void solve(TreeNode* root,int sum,int &targetSum,vector<int> v){
        if(root==NULL) return;
        v.push_back(root->val);
        sum+=root->val;
        
        if(root->left!=NULL) solve(root->left,sum,targetSum,v);
        if(root->right!=NULL) solve(root->right,sum,targetSum,v);
        
        if(sum==targetSum && root->left==NULL && root->right==NULL) ans.push_back(v); 
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> v;
        int sum=0;
        solve(root,sum,targetSum,v);
        
        return ans;
    }
};