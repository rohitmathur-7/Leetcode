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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* tmp=root;
        while(true){
            if(tmp!=NULL){
                st.push(tmp);
                tmp=tmp->left;
            }
            else{
                if(st.empty()) break;
                TreeNode* tp=st.top();
                ans.push_back(tp->val);
                tmp=tp->right;
                st.pop();
            }
        }
        return ans;
    }
};