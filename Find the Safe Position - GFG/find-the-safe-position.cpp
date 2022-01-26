// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    void solve(int n,int k,vector<int>& v,int idx){
         if(v.size()==1) return;
         idx=(idx+k)%v.size();
         v.erase(v.begin()+idx);
         solve(n,k,v,idx);
         return;
    }
    int safePos(int n, int k) {
        // code here
        k--;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            v[i]=i+1;
        }
        solve(n,k,v,0);
        return v[0];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        
        cin>>n>>k;

        Solution ob;
        cout << ob.safePos(n,k) << endl;
    }
    return 0;
}  // } Driver Code Ends