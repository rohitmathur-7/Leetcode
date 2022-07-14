class Solution {
public:
    
    int findLowestCoins(vector<int> &coins, int cur, int amount,vector<vector<int> > &dp){  
        if (cur == coins.size() || amount <= 0)
            return (amount == 0) ? 0 : INT_MAX - 1;   
        
        if (dp[cur][amount] != -1)
            return dp[cur][amount];
        
        // int res = -1;
        if (coins[cur] > amount) {
            return dp[cur][amount]=findLowestCoins(coins,cur+1,amount,dp);
            // res = doNotTakeCoin;
        }
        else {
            int takeCoin = 1 + findLowestCoins(coins,cur,amount-coins[cur],dp);
            int doNotTakeCoin = findLowestCoins(coins,cur+1,amount,dp);
            return dp[cur][amount] = min(takeCoin, doNotTakeCoin);
        }
        // return dp[cur][amount] = res;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int> > dp(n+1,vector<int>(amount+1,-1));
        int res = findLowestCoins(coins,0,amount,dp);
        return (res == INT_MAX - 1 ) ? -1 : res;
    }
};