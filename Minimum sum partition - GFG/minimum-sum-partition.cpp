//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
  
    int solve(int arr[], int &n,int idx,int s1,int sum,vector<vector<int>> &dp){
        if(idx==n){
            int rem=sum-s1;
            return abs(s1-rem);
        }
        
        if(dp[idx][s1]!=-1) return dp[idx][s1];
        
        int a1=solve(arr,n,idx+1,s1+arr[idx],sum,dp);
        int a2=solve(arr,n,idx+1,s1,sum,dp);
        
        return dp[idx][s1]=min(a1,a2);
    }
  
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    for(int i=0;i<n;i++) sum+=arr[i];
	    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
	    return solve(arr,n,0,0,sum,dp);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends