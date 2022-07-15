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
    
    TreeNode* build(vector<int>& postorder,vector<int>& inorder,int &rootIdx,int left,int right,map<int,int> &mp){
        if(left>right) return NULL;
        int inPos=mp[postorder[rootIdx]];
        rootIdx--;
        TreeNode* root=new TreeNode(inorder[inPos]);
        root->right=build(postorder,inorder,rootIdx,inPos+1,right,mp);
        root->left=build(postorder,inorder,rootIdx,left,inPos-1,mp);
        
        return root;        
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int rootIdx=postorder.size()-1;
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return build(postorder,inorder,rootIdx,0,inorder.size()-1,mp);
    }
};