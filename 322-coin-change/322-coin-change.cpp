class Solution {
public:
    
    int findLowestCoins(vector<int> &coins, int cur, int amount,vector<vector<int> > &dp){  
        if (cur == coins.size() || amount <= 0)
            return (amount == 0) ? 0 : INT_MAX - 1;   
        
        if (dp[cur][amount] != -1)
            return dp[cur][amount];
        
        if (coins[cur] > amount) {
            return dp[cur][amount]=findLowestCoins(coins,cur+1,amount,dp);
        }
        else {
            return dp[cur][amount]=min(1 + findLowestCoins(coins,cur,amount-coins[cur],dp),findLowestCoins(coins,cur+1,amount,dp));
        }
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int> > dp(n+1,vector<int>(amount+1,-1));
        int res = findLowestCoins(coins,0,amount,dp);
        return (res == INT_MAX - 1 ) ? -1 : res;
    }
};