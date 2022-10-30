class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid){
        int n=grid.size();
        
        if(grid[0][0] || grid[n-1][n-1]) return -1;
        
        vector<pair<int,int>> directions={{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
        
        queue<vector<int>> q;
        q.push({0,0,1});
        grid[0][0]=1;
        
        while(!q.empty()){
            auto ele=q.front();
            q.pop();
            if(ele[0]==n-1 && ele[1]==n-1) return ele[2];
            
            for(auto x:directions){
                int new_x=ele[0]+x.first;
                int new_y=ele[1]+x.second;
                
                if(new_x>=0 && new_x<n && new_y>=0 && new_y<n && grid[new_x][new_y]==0){
                    q.push({new_x,new_y,ele[2]+1});
                    grid[new_x][new_y]=1;
                }
            }
        }
        
        return -1;
    }
};