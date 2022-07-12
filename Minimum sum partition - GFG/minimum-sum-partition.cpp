// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
    int solve(int arr[],int n,int idx,int sum,int total,vector<vector<int> > &dp){
        if(idx==n){
            int d=total-sum;
            int diff=abs(d-sum);
            return diff;
        }
        
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        
        return dp[idx][sum]=min(solve(arr,n,idx+1,sum+arr[idx],total,dp),solve(arr,n,idx+1,sum,total,dp));
        
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    for(int i=0;i<n;i++) sum+=arr[i];
	    vector<vector<int> > dp(n+1,vector<int>(sum+1,-1));
	    return solve(arr,n,0,0,sum,dp);
	} 
};


// { Driver Code Starts.
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
}  // } Driver Code Ends