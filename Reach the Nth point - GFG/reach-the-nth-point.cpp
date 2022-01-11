// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	    int solve(int n,int* dp){
	        if(n==1) return 1;
		    if(n==2) return 2;
		    if(dp[n]!=-1) return dp[n];
		    dp[n-1]=solve(n-1,dp)%1000000007;
		    dp[n-2]=solve(n-2,dp)%1000000007;
		    return (dp[n-1]+dp[n-2])%1000000007;
	    }
		int nthPoint(int n){
		    // Code here
		    if(n==1 || n==2) return n;
		    int dp[n+1];
		    for(int i=0;i<=n;i++) dp[i]=-1;
		    dp[1]=1,dp[2]=2;
		    return (solve(n,dp))%1000000007;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends