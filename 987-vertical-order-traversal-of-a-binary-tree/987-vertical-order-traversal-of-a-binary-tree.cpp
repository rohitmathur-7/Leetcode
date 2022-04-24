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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*,int> > q;
        map<int,vector<int> > mp;
        map<int,vector<int> > new_mp;
        q.push({root,0});
        while(!q.empty()){
            int sze=q.size();
            map<int,vector<int> > tmp;    
            for(int i=0;i<sze;i++){
                auto tp=q.front();
                tmp[tp.second].push_back(tp.first->val);
                if(tp.first->left!=NULL){
                    q.push({tp.first->left,tp.second-1});
                }
                if(tp.first->right!=NULL){
                    q.push({tp.first->right,tp.second+1});
                }
                q.pop();    
            }
            for(auto x:tmp){
                sort(x.second.begin(),x.second.end());
                for(auto y:x.second){
                    new_mp[x.first].push_back(y);
                }
            }
        }
        for(auto x:new_mp){
            mp[x.first]=x.second;
        }
        for(auto x:mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};















