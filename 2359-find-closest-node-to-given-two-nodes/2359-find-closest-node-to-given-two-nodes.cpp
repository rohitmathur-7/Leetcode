class Solution {
public:
    
    void bfs(int node,vector<int> &edges,vector<int> &dist){
        dist[node]=0;
        queue<int> q;
        q.push(node);
        
        while(!q.empty()){
            int a=q.front();
            q.pop();
            if(edges[a]!=-1 && dist[edges[a]]==-1){
                dist[edges[a]]=dist[a]+1;
                q.push(edges[a]);
            }
        }
        
        
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2){
        int n=edges.size();
        vector<int> a(n,-1),b(n,-1);
        
        bfs(node1,edges,a);
        bfs(node2,edges,b);
        
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