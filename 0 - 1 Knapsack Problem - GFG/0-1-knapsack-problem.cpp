// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    int solve(int W,int wt[],int val[],int n,int idx,vector<vector<int> > &dp){
        
        if(idx==n || W==0) return 0;
        
        if(dp[idx][W]!=-1) return dp[idx][W];
        
        if(wt[idx]<=W){
            return dp[idx][W]=max(val[idx]+solve(W-wt[idx],wt,val,n,idx+1,dp),solve(W,wt,val,n,idx+1,dp));
        }
        else return dp[idx][W]=solve(W,wt,val,n,idx+1,dp);
    }
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) { 
       // Your code here
       vector<vector<int> > dp(n,vector<int>(W+1,-1));
       return solve(W,wt,val,n,0,dp);
       
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends