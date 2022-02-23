class Solution {
public:
    bool canPlace(int row,int col,char element,vector<vector<char>> board){
        for(int i=0;i<9;i++){
            if(board[row][i]==element) return false;
            if(board[i][col]==element) return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==element) return false;
        }
//         int upc=(ceil((float)col/3)*3)-1;
//         int downc=((col/3)*3);
//         int upr=(ceil((float)row/3)*3)-1;
//         int downr=((row/3)*3);
        
//         for(int i=downr;i<=upr;i++){
//             for(int j=downc;j<=upc;j++){
//                 if(board[i][j]==element) return false;
//             }
//         }
        
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(canPlace(i,j,c,board)){
                            board[i][j]=c;
                            if(solve(board)) return true;
                            else board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};