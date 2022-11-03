//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    int solve(vector<int>& arr, int &k,int l,int r,vector<vector<int>> &dp){
        if(l==r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int mx=*max_element(arr.begin()+l,arr.begin()+r+1);
        int mn=*min_element(arr.begin()+l,arr.begin()+r+1);
        if((mx-mn)<=k) return 0;
        
        return dp[l][r]=1+min(solve(arr,k,l+1,r,dp),solve(arr,k,l,r-1,dp));
    }
    
    int removals(vector<int>& arr, int k){
        //Code here
        vector<vector<int>> dp(arr.size(),vector<int>(arr.size(),-1));
        sort(arr.begin(),arr.end());
        return solve(arr,k,0,arr.size()-1,dp);
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends