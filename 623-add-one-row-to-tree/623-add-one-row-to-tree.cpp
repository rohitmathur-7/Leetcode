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
    
    void solve(TreeNode* root,int val,int depth,int cur){
        if(root==NULL) return;
        if(cur==depth-1){
            TreeNode* tmp1=new TreeNode;
            TreeNode* tmp2=new TreeNode;
            tmp1->val=val;
            tmp2->val=val;
            if(root->left) tmp1->left=root->left;
            if(root->right) tmp2->right=root->right;
            root->left=tmp1;
            root->right=tmp2;
            return;
        }    
        solve(root->left,val,depth,cur+1);
        solve(root->right,val,depth,cur+1);
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* tmp=new TreeNode;
            tmp->val=val;
            if(root) tmp->left=root;
            return tmp;
        }
        solve(root,val,depth,1);
        return root;
    }
};