class Solution {
public:
    
    bool dfs(vector<vector<int>>& graph,int i,vector<int> &color,int cur){
        color[i]=cur;
        
        for(auto x:graph[i]){
            if(color[x]==-1){
                int c=(cur==0)?1:0;
                if(!dfs(graph,x,color,c)) return false;
            }
            else if(cur==color[x]) return false;
        }
        
        return true;   
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!dfs(graph,i,color,0)) return false;
            }
        }
        
        return true;
    }
};