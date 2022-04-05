class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph){
        int n=graph.size();
        vector<int> color(n,-1);
        queue<int> q;
        color[0]=0;
        vector<bool> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                q.push(i);
                while(!q.empty()){
                    int a=q.front();
                    q.pop();
                    vis[a]=true;
                    for(auto x:graph[a]){
                        if(color[x]==-1){
                            color[x]=color[a]==0?1:0;
                            q.push(x);
                        }
                        else if(color[x]==color[a]) return false;
                    }
                }      
            }
        }
        
        return true;
    }
};