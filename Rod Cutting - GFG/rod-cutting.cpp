// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int solve(int price[],int n,int idx,int len,vector<vector<int> > &dp){
        if(idx>=n || len>=n) return 0;
        if(dp[idx][len]!=-1) return dp[idx][len];
        
        int take=INT_MIN;
        if(len+idx+1<=n) take=price[idx]+solve(price,n,idx,len+idx+1,dp);
        int not_take=solve(price,n,idx+1,len,dp);
        
        return dp[idx][len]=max(take,not_take);
    }
  
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int> > dp(n+1,vector<int>(n+1,-1));
        return solve(price,n,0,0,dp);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends