class Solution {
public:
    
    int solve(vector<int> &coins,int cur,int amount,vector<vector<int> > &dp){
        if(cur==coins.size() || amount<=0)
            return (amount==0)?0:INT_MAX-1;
        
        if(dp[cur][amount] != -1) 
            return dp[cur][amount];
        
        if(coins[cur]>amount){
            return dp[cur][amount]=solve(coins,cur+1,amount,dp);
        }
        else{
            return dp[cur][amount]=min(solve(coins,cur+1,amount,dp),1+solve(coins,cur,amount-coins[cur],dp));
        }
        
    }
    
    int coinChange(vector<int>& coins, int amount){
        int n=coins.size();
        vector<vector<int> > dp(n+1,vector<int>(amount+1,-1));
        
        int ans=solve(coins,0,amount,dp);
        return (ans==INT_MAX-1)?-1:ans;
    }
};