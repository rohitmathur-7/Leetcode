class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> ans;
        for(int i=0;i<m;i++){
            int x=0,y=i;
            while(1){
                if(grid[x][y]==1){
                    if((y+1)<m){
                        if(grid[x][y+1]==-1){
                            ans.push_back(-1);
                            break;    
                        }
                        else{
                            x++;
                            y++;
                            if(x==n){
                                ans.push_back(y);
                                break;
                            }
                            if(y==m){
                                ans.push_back(-1);
                                break;   
                            }
                        }
                    }
                    else{
                        ans.push_back(-1);
                        break;  
                    }
                }
                else{
                    if((y-1)>=0){
                        if(grid[x][y-1]==1){
                            ans.push_back(-1);
                            break;    
                        }
                        else{
                            x++;
                            y--;
                            if(x==n){
                                ans.push_back(y);
                                break;
                            }
                            if(y==-1){
                                ans.push_back(-1);
                                break;   
                            }
                        }
                    }
                    else{
                        ans.push_back(-1);
                        break; 
                    }
                }
            }
        }
        
        return ans;
    }
};