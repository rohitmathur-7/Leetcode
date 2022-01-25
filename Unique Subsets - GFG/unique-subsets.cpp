// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    void solve(vector<int> arr,vector<int> v,set<vector<int>>& s,int i){
        if(arr.size()==i){
            s.insert(v);
            return;
        }
        solve(arr,v,s,i+1);
        v.push_back(arr[i]);
        solve(arr,v,s,i+1);
        return;
    }
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        // code here 
        set<vector<int>> s;
        vector<int> v;
        int i=0;
        sort(arr.begin(),arr.end());
        solve(arr,v,s,0);
        vector<vector<int> > ans;
        for(auto x:s){
            ans.push_back(x);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends