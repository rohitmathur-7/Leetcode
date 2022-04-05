class Solution {
public:
    int numIslands(vector<vector<char>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        queue<pair<int,int>> q;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]=='1'){
                    ans++;
                    q.push({i,j});
                    while(!q.empty()){
                        int x=q.front().first;
                        int y=q.front().second;
                        arr[x][y]='0';
                        q.pop();
                        if((x+1)<n && arr[x+1][y]=='1'){
                            arr[x+1][y]='0';
                            q.push({x+1,y});
                        }
                        if((x-1)>=0 && arr[x-1][y]=='1'){
                            arr[x-1][y]='0';
                            q.push({x-1,y});
                        }
                        if((y+1)<m && arr[x][y+1]=='1'){
                            arr[x][y+1]='0';
                            q.push({x,y+1});
                        }
                        if((y-1)>=0 && arr[x][y-1]=='1'){
                            arr[x][y-1]='0';
                            q.push({x,y-1});
                        }
                    }
                }
            }
        }
        return ans;
    }
};