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
  TreeNode* build(vector<int>& preorder,int preStart,int preEnd,vector<int>& inorder,int inStart,int inEnd,map<int,int> &mp){
        if(preStart>preEnd || inStart>inEnd) return NULL;
        
        TreeNode* root=new TreeNode(preorder[preStart]);
        int inPos=mp[preorder[preStart]]; //position of root in inorder, all elements left to this position will be left part of root
        int ele_to_left=inPos-inStart;
        
        root->left=build(preorder,preStart+1,preStart+ele_to_left,inorder,inStart,inPos-1,mp);
        
        root->right=build(preorder,preStart+ele_to_left+1,preEnd,inorder,inPos+1,inEnd,mp);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++) mp[inorder[i]]=i;
        return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
    }
    
};