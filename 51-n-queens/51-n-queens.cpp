class Solution {
public:
    bool isSafeToPlaceQueen(int idx,int j,vector<string>& board,int n){
        for(int i=idx-1;i>=0;i--){
            if(board[i][j]=='Q') return false;//check for top
        }
        int x,y;
        for(x=idx-1,y=j-1;x>=0 && y>=0;x--,y--){
            if(board[x][y]=='Q') return false;//check for top-left        
        }
        for(x=idx-1,y=j+1;x>=0 && y<n;x--,y++){
            if(board[x][y]=='Q') return false;//check for top-right        
        }
        return true;
    }
    bool solve(vector<vector<string>>& ans,vector<string>& board,int idx,int n){
        if(idx==n){
            vector<string> res;
            for(int i=0;i<n;i++){
                string tmp;
                for(int j=0;j<n;j++){
                    tmp+=board[i][j];
                }
                res.push_back(tmp);
            }
            ans.push_back(res);
            return false;
        }
        
        for(int j=0;j<n;j++){
            if(isSafeToPlaceQueen(idx,j,board,n)){
                board[idx][j]='Q';
                if(solve(ans,board,idx+1,n)) return true;
                board[idx][j]='.';
            }
        }
        
        return false;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        // char board[n][n];
        vector<string> board(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                board[i][j]='.';
            }
        }
        solve(ans,board,0,n);
        return ans;
    }
};