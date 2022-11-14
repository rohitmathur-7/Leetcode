//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int numberOfSubsequences(string s, string w){
        // code here 
        int ans=0,n=s.size(),m=w.size();
        int cur;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i] && s[i]==w[0]){
                cur=0;
                for(int j=i;j<n;j++){
                    if(!vis[j] && s[j]==w[cur]){
                        cur++;
                        vis[j]=true;
                    }
                    if(cur==m){
                        ans++;
                        break;
                    }
                }    
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends