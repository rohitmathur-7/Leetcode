class Solution {
public:
    void solve(vector<vector<int>> &ans,vector<int> &ds,vector<int> nums,map<int,bool> &mp){
        
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(!mp[i]){
                ds.push_back(nums[i]);
                mp[i]=true;
                solve(ans,ds,nums,mp);
                ds.pop_back();
                mp[i]=false;
            }
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        map<int,bool> mp;
        solve(ans,ds,nums,mp);
        
        return ans;
    }
};