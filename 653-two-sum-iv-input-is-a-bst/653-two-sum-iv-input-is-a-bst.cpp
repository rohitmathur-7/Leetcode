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
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> st;
        vector<int> v;
        do{
            while(root!=NULL){
                st.push(root);
                root=root->left;
            }
            root=st.top();st.pop();
            v.push_back(root->val);
            root=root->right;
        }while(!st.empty() || root!=NULL);
        
        unordered_map<int,bool> mp;
        for(auto x:v){
            if(mp[k-x]) return true;
            mp[x]=true;
        }
        
        return false;
    }
};