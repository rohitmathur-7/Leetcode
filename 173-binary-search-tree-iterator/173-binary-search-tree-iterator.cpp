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
class BSTIterator {
public:
    vector<int> inorder;
    int p=0;
    BSTIterator(TreeNode* root) {
        stack<TreeNode*> st;
        do{
            while(root!=NULL){
                st.push(root);
                root=root->left;
            }
            root=st.top();
            st.pop();
            inorder.push_back(root->val);
            root=root->right;
        }while(!st.empty() || root!=NULL);
    }
    
    int next() {
        return inorder[p++];
    }
    
    bool hasNext() {
        return p<inorder.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */