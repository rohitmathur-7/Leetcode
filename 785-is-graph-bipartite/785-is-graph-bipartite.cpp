class Solution {
public:
    bool dfs(int idx,vector<int> &color,vector<vector<int>> graph,int cur){
        color[idx]=cur;
        for(auto x:graph[idx]){
            if(color[x]==-1){
                int c=(cur==0)?1:0;
                if(!dfs(x,color,graph,c)) return false;
            }
            else if(color[x]==color[idx]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph){
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!dfs(i,color,graph,0)) return false;    
            }
        }
        return true;
    }
};