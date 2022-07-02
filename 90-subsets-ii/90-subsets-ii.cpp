class Solution {
public:
    void solve(int idx,vector<int> nums,vector<int> ds,vector<vector<int> > &ans,int n){
        ans.push_back(ds);
        for(int i=idx;i<n;i++){
            if(i!=idx && nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            solve(i+1,nums,ds,ans,n);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int> > ans;
        vector<int> ds;
        solve(0,nums,ds,ans,n);
        
        return ans;
    }
};