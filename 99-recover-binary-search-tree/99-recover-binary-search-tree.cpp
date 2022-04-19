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
    void new_inorder(TreeNode* root,int a,int b){
        if(root==NULL) return;
        new_inorder(root->left,a,b);
        if(root->val==a) root->val=b;
        else if(root->val==b) root->val=a;
        new_inorder(root->right,a,b);
    }
    void inorder(TreeNode* root,vector<int> &v){
        if(root==NULL) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    void recoverTree(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
        vector<int> tmp=v;
        sort(tmp.begin(),tmp.end());
        int a,b;
        bool g=false;
        for(int i=0;i<tmp.size();i++){
            if(tmp[i]!=v[i]){
                if(!g){
                    a=v[i];
                    g=true;
                }
                else{
                    b=v[i];
                }
            }
        }
        new_inorder(root,a,b);
    }
};