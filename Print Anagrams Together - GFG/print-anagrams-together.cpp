// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& s) {
        //code here
        int n=s.size();
        vector<vector<string> > ans;
        bool vis[n];
        for(int i=0;i<n;i++) vis[i]=false;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i]=true;
                map<char,int> m;
                vector<string> v;
                v.push_back(s[i]);
                for(int j=0;j<s[i].size();j++){
                    m[s[i][j]]++;
                }
                for(int j=i+1;j<n;j++){
                    map<char,int> m1;
                    bool g=true;
                    for(int k=0;k<s[j].size();k++){
                        m1[s[j][k]]++;
                        if(!m[s[j][k]]){
                            g=false;break;
                        }
                    }
                    if(g){
                        for(auto x:m){
                            if(x.second!=m1[x.first]){
                                g=false;
                                break;
                            }
                        }
                        if(g){
                            v.push_back(s[j]);    
                            vis[j]=true;
                        }
                    }
                }
                ans.push_back(v);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends