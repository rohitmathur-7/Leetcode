class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<=m;i++){
            dp[0][i]=0;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        string scs;
        int a=n,b=m;
        while(a>0 && b>0){
            if(text1[a-1]==text2[b-1]){
                scs+=text1[a-1];
                a--,b--;
            }
            else{
                if(dp[a-1][b] >= dp[a][b-1]){
                    scs+=text1[a-1];
                    a--;
                }
                else{
                    scs+=text2[b-1];
                    b--;
                }
            }
        }
        
        while(a>0){
            scs+=text1[a-1];
            a--;
        }
        while(b>0){
            scs+=text2[b-1];
            b--;
        }
        
        reverse(scs.begin(),scs.end());
         
        return scs;        
    }
};