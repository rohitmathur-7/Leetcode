// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int mod=1000000007;
	int solve(int arr[],int n,int sum,int idx,int cur,vector<vector<int> > &dp){
	    if(cur>sum) return 0;
	    if(idx==n){
	        if(cur==sum) return 1;
	        return 0;
	    }
	    
	    if(dp[idx][cur]!=-1){
	       // cout<<"idx: "<<idx<<" cur: "<<cur<<endl;
	        return dp[idx][cur]%mod;
	    }
	    
	    return dp[idx][cur]=((solve(arr,n,sum,idx+1,cur,dp))%mod+(solve(arr,n,sum,idx+1,cur+arr[idx],dp))%mod)%mod;
	}
	
	int perfectSum(int arr[],int n,int sum){
        // Your code goes here
        vector<vector<int> > dp(n+1,vector<int>(sum+1,-1));
        return solve(arr,n,sum,0,0,dp)%mod;
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends