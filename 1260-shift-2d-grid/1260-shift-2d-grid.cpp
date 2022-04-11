class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> tmp(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((j+k)>=m){
                    int nr=(i+((j+k)/m))%n;
                    int nc=(j+k)%m;
                    tmp[nr][nc]=grid[i][j];
                }
                else{
                    tmp[i][j+k]=grid[i][j];
                }
            }
        }
        return tmp;
    }
};