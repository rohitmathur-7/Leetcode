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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode* > q;
        q.push(root);
        bool LeftToRight=true;
        while(!q.empty()){
            int n=q.size();
            vector<int> tmp(n);
            TreeNode* node;
            for(int i=0;i<n;i++){
                node=q.front();q.pop();
                if(LeftToRight) tmp[i]=node->val;
                else tmp[n-1-i]=node->val;
                
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);    
            }
            LeftToRight = !LeftToRight;
            ans.push_back(tmp);
        }
        return ans;
    }
};