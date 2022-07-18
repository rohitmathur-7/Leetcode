class Solution {
public:
    int dp[1005][1005];
    int solve(int n,int m,string &text1,string &text2){
        if(n==0 || m==0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        
        if(text1[n-1]==text2[m-1]){
            return dp[n][m]=1+solve(n-1,m-1,text1,text2);
        }
        else{
            return dp[n][m]=max(solve(n-1,m,text1,text2),solve(n,m-1,text1,text2));
        }
        
    }
    
    int longestCommonSubsequence(string text1, string text2){
        memset(dp,-1,sizeof(dp));
        int n=text1.size(),m=text2.size();
        return solve(n,m,text1,text2);
    }
};