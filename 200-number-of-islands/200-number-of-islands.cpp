class Solution {
public:
    
    void dfs(vector<vector<char>>& grid,vector<vector<bool> > &vis,int i,int j,int &n,int &m){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]=='0' || vis[i][j]) return;
        
        vis[i][j]=true;
        dfs(grid,vis,i-1,j,n,m);
        dfs(grid,vis,i+1,j,n,m);
        dfs(grid,vis,i,j-1,n,m);
        dfs(grid,vis,i,j+1,n,m);
    }
    
    int numIslands(vector<vector<char>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool> > vis(n,vector<bool>(m,false));
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    ans++;
                    dfs(grid,vis,i,j,n,m);
                }
            }
        }
        
        return ans;
    }
};