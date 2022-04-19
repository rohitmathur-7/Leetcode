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
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> ans;
        if(root==NULL) return ans;
        stack<TreeNode*> st;
        TreeNode* tmp=root;
        st.push(tmp);
        while(!st.empty()){
            tmp=st.top();
            st.pop();
            ans.push_back(tmp->val);
            if(tmp->right!=NULL){
                st.push(tmp->right);
            }
            if(tmp->left!=NULL){
                st.push(tmp->left);
            }
        }
        return ans;
    }
};