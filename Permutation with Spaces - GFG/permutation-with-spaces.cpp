// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    void solve(string s,string out,int i,vector<string>& ans){
        if(i>=out.size()-1){
            ans.push_back(out);
            return;
        }
        solve(s,out,i+1,ans);
        string a=" ";
        out.insert(i+1,a);
        solve(s,out,i+2,ans);
        return;
    }
    vector<string> permutation(string s){
        // Code Here
        string out=s;
        vector<string> ans;
        solve(s,out,0,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}
  // } Driver Code Ends