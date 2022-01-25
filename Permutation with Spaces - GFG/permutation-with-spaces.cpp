// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    
    void solve(string s,string out,vector<string>& ans){
        if(s.size()==0){
            ans.push_back(out);
            return;
        }
        string s1=out;
        string s2=out;
        s1.push_back(' ');
        s1.push_back(s[0]);
        s2.push_back(s[0]);
        s.erase(s.begin()+0);
        solve(s,s1,ans);
        solve(s,s2,ans);
        return;
    }

    vector<string> permutation(string s){
        // Code Here
        string out;
        out.push_back(s[0]);
        s.erase(s.begin()+0);
        vector<string> ans;
        solve(s,out,ans);
        // sort(ans.begin(),ans.end());
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