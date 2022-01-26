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
    void get(TreeNode* root,vector<int>& v){
        if(root==NULL) return;
        v.push_back(root->val);
        get(root->left,v);
        get(root->right,v);
        return;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2){
        vector<int> v1,v2;
        get(root1,v1);
        get(root2,v1);
        sort(v1.begin(),v1.end());
        return v1;
    }
};