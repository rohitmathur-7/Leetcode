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
        int c=0;
        while(!q.empty()){
            int n=q.size();
            vector<int> tmp;
            stack<TreeNode* > st;
            TreeNode* node;
            for(int i=0;i<n;i++){
                node=q.front();q.pop();
                if(c%2==0){
                    if(node->left!=NULL) st.push(node->left);
                    if(node->right!=NULL) st.push(node->right);    
                }
                else{
                    if(node->right!=NULL) st.push(node->right); 
                    if(node->left!=NULL) st.push(node->left);
                }
                
                tmp.push_back(node->val);
            }
            while(!st.empty()){
                q.push(st.top());
                st.pop();
            }
            ans.push_back(tmp);
            c++;
        }
        return ans;
    }
};