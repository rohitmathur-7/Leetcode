class Solution {
public:
    void dfs(int i,int j,vector<vector<bool>> &vis,vector<vector<char>> &arr,int n,int m){
        if(i>=n || j>=m || i<0 || j<0 || arr[i][j]=='0' || vis[i][j]) return;
        vis[i][j]=true;
        arr[i][j]='0';
        dfs(i+1,j,vis,arr,n,m);
        dfs(i-1,j,vis,arr,n,m);
        dfs(i,j+1,vis,arr,n,m);
        dfs(i,j-1,vis,arr,n,m);
    }
    int numIslands(vector<vector<char>>& arr){
        int n=arr.size();
        int m=arr[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]=='1'){
                    ans++;
                    dfs(i,j,vis,arr,n,m);
                }
            }
        }
        return ans;
    }
};