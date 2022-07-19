class Solution {
public:
    int minDistance(string word1, string word2){
        int n=word1.size(),m=word2.size();
        int dp[n+1][m+1];   
        for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }
        for(int i=0;i<=m;i++){
            dp[0][i]=i;
        }
        
        int insert,deletee,replace;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    insert=1+dp[i][j-1];
                    deletee=1+dp[i-1][j];
                    replace=1+dp[i-1][j-1];
                    
                    dp[i][j]=min({insert,deletee,replace});
                }
            }
        }
        
        return dp[n][m];
        
    }
};