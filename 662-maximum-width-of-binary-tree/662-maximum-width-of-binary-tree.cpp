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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int ans=0;
        while(!q.empty()){
            int mn=q.front().second;
            int first,last;
            int sze=q.size();
            for(int i=0;i<sze;i++){
                unsigned int cur_id=q.front().second-mn;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0) first=cur_id;
                if(i==sze-1) last=cur_id;
                if(node->left!=NULL) q.push({node->left,unsigned(2*cur_id)+1});
                if(node->right!=NULL) q.push({node->right,unsigned(2*cur_id)+2});
            }
            ans=unsigned(max(ans,last-first+1));
        }
        return ans;
    }
};











