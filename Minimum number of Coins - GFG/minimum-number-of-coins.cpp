//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        // code here
        vector<int> ans;
        vector<int> arr={ 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        while(N>0){
            int pos=lower_bound(arr.begin(),arr.end(),N)-arr.begin();
            if(lower_bound(arr.begin(),arr.end(),N)==arr.end()) pos=9;
            if(N<arr[pos]) pos--;
            int d=N/arr[pos];
            N-=(arr[pos]*d);
            for(int i=0;i<d;i++) ans.push_back(arr[pos]);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends