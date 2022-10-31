class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        for(int i=0;i<n;i++){
            int x=i+1,y=1;
            while(x<n && y<m){
                if(matrix[x][y]!=matrix[i][0]) return false;
                x+=1;
                y+=1;
            }
        }
        for(int i=0;i<m;i++){
            int x=1,y=i+1;
            while(x<n && y<m){
                if(matrix[x][y]!=matrix[0][i]) return false;
                x+=1;
                y+=1;
            }
        }
        
        return true;
    }
};