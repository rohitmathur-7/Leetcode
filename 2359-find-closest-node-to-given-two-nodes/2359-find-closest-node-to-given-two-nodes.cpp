class Solution {
public:
    
    void dfs(int node,vector<int> &edges,int c,vector<int> &dist){
        while(node!=-1 && dist[node]==-1){
            dist[node]=c++;
            node=edges[node];
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2){
        int n=edges.size();
        vector<int> a(n,-1),b(n,-1);
        
        dfs(node1,edges,0,a);
        dfs(node2,edges,0,b);
        
        int mn=INT_MAX,ans=-1;
        for(int i=0;i<n;i++){
            if(min(a[i],b[i])>=0 && max(a[i],b[i])<mn){
                mn=max(a[i],b[i]);
                ans=i;
            }
        }
        
        return ans;
        
    }
};