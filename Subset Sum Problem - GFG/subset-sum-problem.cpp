// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool solve(int idx,vector<int> arr,int sum,int curr,vector<vector<int> > &dp){
        if(curr>sum) return false;
        if(idx==arr.size()){
            if(curr==sum) return true;
            return false;
        }
        
        if(dp[idx][curr]!=-1) return dp[idx][curr];
        
        bool g1,g2,ans;
        
        g1=solve(idx+1,arr,sum,curr,dp);
        g2=solve(idx+1,arr,sum,curr+arr[idx],dp);
        ans=g1||g2;
    
        return dp[idx][curr]=ans;
    }

    bool isSubsetSum(vector<int> arr,int sum){
        // code here 
        vector<vector<int> > dp(arr.size(),vector<int>(sum+1,-1));
        return solve(0,arr,sum,0,dp);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends