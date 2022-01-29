class Solution {
public:
    void solve(int ind,vector<vector<int>>& ans,vector<int> out,vector<int> candidates,int target){
        if(target==0){
            ans.push_back(out);
            return;
        }
        for(int i=ind;i<candidates.size();i++){
            if(i>ind && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            out.push_back(candidates[i]);
            solve(i+1,ans,out,candidates,target-candidates[i]);
            out.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> out;
        solve(0,ans,out,candidates,target);
        return ans;
    }
};