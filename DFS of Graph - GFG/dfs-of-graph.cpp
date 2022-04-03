// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    void dfs(int x,vector<int> adj[],vector<int>& ans,vector<bool>& visited){
        for(auto y: adj[x]){
            if(!visited[y]){
                visited[y]=true;
                ans.push_back(y);
                dfs(y,adj,ans,visited);
            }        
        }
    }
  
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]){
        // Code here
        vector<bool> visited(V);
        for(int i=0;i<V;i++) visited[i]=false;
        vector<int> ans;
        ans.push_back(0);
        visited[0]=true;
        for(auto x: adj[0]){
            if(!visited[x]){
                visited[x]=true;
                ans.push_back(x);
                dfs(x,adj,ans,visited);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends