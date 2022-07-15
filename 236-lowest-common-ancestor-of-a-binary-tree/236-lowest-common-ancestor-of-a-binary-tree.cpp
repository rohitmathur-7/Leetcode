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
    bool solve(TreeNode* root,TreeNode* cur,vector<TreeNode*> &tmp){
        if(root==NULL) return false;
        if(root->val==cur->val){
            tmp.push_back(cur);
            return true;
        }
        
        if(solve(root->left,cur,tmp) || solve(root->right,cur,tmp)){
            tmp.push_back(root);
            return true;
        }
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> a,b;
        solve(root,p,a);
        solve(root,q,b);
        TreeNode* ans;
        for(auto x:a){
            if(find(b.begin(),b.end(),x)!=b.end()){
                ans=x;
                break;
            }
        }
        
        return ans;
    }
};