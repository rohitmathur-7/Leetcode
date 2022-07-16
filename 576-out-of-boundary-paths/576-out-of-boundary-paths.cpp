class Solution{
public:
    int mod=1e9+7;
    int solve(int m, int n, int maxMove, int startRow, int startColumn,vector<vector<vector<int>>> &dp){
        if(startRow>=m || startColumn>=n || startRow<0 || startColumn<0) return 1;
        if(maxMove==0) return 0;
        
        if(dp[startRow][startColumn][maxMove]!=-1) return dp[startRow][startColumn][maxMove]%mod;
        
        int a=solve(m,n,maxMove-1,startRow+1,startColumn,dp)%mod;
        int b=solve(m,n,maxMove-1,startRow-1,startColumn,dp)%mod;
        int c=solve(m,n,maxMove-1,startRow,startColumn+1,dp)%mod;
        int d=solve(m,n,maxMove-1,startRow,startColumn-1,dp)%mod;
        
        return dp[startRow][startColumn][maxMove]=((((a%mod+b%mod)%mod+c%mod)%mod+d%mod)%mod)%mod;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn){
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(maxMove+1,-1)));
        return solve(m,n,maxMove,startRow,startColumn,dp)%mod;
    }
};