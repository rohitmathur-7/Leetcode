class Solution {
public:
    int dp[101][201];
    
    bool solve(string s1,string s2,string s3,int idx1,int idx2,int idx3){
        if(idx3==s3.size()){
            if(idx1==s1.size() && idx2==s2.size()){
                return true;
            }
            return false;
        }
        
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        
        bool ans1=false;
        if(s1[idx1]==s3[idx3]){
            ans1=solve(s1,s2,s3,idx1+1,idx2,idx3+1);
        }
        
        if(!ans1 && s2[idx2]==s3[idx3]){
            ans1=solve(s1,s2,s3,idx1,idx2+1,idx3+1);
        }
        
        dp[idx1][idx2]=(ans1);
        
        return dp[idx1][idx2];
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp));
        return solve(s1,s2,s3,0,0,0);
    }
    
};