// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void sum(int csum,int idx,vector<int> arr,int n,vector<int>& ans){
        if(idx==n) return;
        for(int j=idx;j<n;j++){
            ans.push_back(csum+arr[j]);
            sum(csum+arr[j],j+1,arr,n,ans);
        }
    }    
    vector<int> subsetSums(vector<int> arr, int n){
        // Write Your Code here
        vector<int> ans;
        ans.push_back(0);
        for(int i=0;i<n;i++){
            ans.push_back(arr[i]);
            sum(arr[i],i+1,arr,n,ans);
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends