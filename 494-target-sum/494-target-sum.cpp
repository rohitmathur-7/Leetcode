class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target){
        int sum=0,z=0;
        for(auto x:nums){
            sum+=x;
            if(x==0) z++;
        }
        
        if(target<0) target*=-1;
        if(target>sum || (target+sum)%2!=0) return 0;
        
        int s1=(target+sum)/2;
        
        int n=nums.size();
        int dp[n+1][s1+1];
        
        for(int i=1;i<=n;i++){
            dp[i][0]=pow(2,z)-1;
        }
        for(int i=1;i<=s1;i++){
            dp[0][i]=0;
        }        
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=s1;j++){
                if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j-nums[i-1]]+dp[i-1][j];
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        
        return dp[n][s1];
        
    }
};