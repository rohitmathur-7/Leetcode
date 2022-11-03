//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int removals(vector<int>& arr, int k){
        //Code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int len=0;
        int i=0,j=0;
        while(i<n && j<n){
            if((arr[j]-arr[i])<=k){
                len=max(len,j-i+1);
                j++;
            }
            else i++;
        }
    
        return n-len;
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