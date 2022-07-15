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
    
    TreeNode* build(vector<int>& postorder,int postStart,int postEnd,vector<int>& inorder,int inStart,int inEnd,map<int,int> &mp){
        if(postStart>postEnd || inStart>inEnd) return NULL;

        TreeNode* root=new TreeNode(postorder[postEnd]);
        int inPos=mp[postorder[postEnd]];
        int nums=inPos-inStart;
        
        root->left=build(postorder,postStart,postStart+nums-1,inorder,inStart,inPos-1,mp);
        root->right=build(postorder,postStart+nums,postEnd-1,inorder,inPos+1,inEnd,mp);
        
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++) mp[inorder[i]]=i;
        
        return build(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mp);
    }
};