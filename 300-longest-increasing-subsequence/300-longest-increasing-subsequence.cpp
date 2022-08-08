class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(vector<int>& nums,int idx,int prev_idx){
        if(idx>=nums.size()) return 0;
        if(dp[idx][prev_idx+1]!=-1) return dp[idx][prev_idx+1];
        
        int include=0,exclude=0;
        exclude=solve(nums,idx+1,prev_idx);
        if(prev_idx==-1 || nums[idx]>nums[prev_idx]){
            include=1+solve(nums,idx+1,idx);
        }
        
        return dp[idx][prev_idx+1]=max(include,exclude);
    }
    
    int lengthOfLIS(vector<int>& nums){
        int sze=nums.size();
        dp.resize(sze,vector<int>(sze,-1));
        
        return solve(nums,0,-1);
    }
};