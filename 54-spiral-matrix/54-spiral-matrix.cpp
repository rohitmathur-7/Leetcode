class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix){
        int n=matrix.size();
        int m=matrix[0].size();
        int r1=0,c1=m-1,r2=n-1,c2=0,cnt=0;
        bool vis[n][m];
        memset(vis,false,sizeof(vis));
        bool lr=true,tb=false,rl=false,bt=false;
        vector<int> ans;
        int i=0,j=0;
        while(cnt<(n*m)){
            // cout<<"i: "<<i<<" j: "<<j<<endl;
            if(lr){
                ans.push_back(matrix[i][j]);
                j++;
                if(j==(c1+1)){
                    lr=false;
                    tb=true;
                    i++;
                    j--;
                    r1++;
                }
            }
            else if(tb){
                ans.push_back(matrix[i][j]);
                i++;
                if(i==(r2+1)){
                    tb=false;
                    rl=true;
                    j--;
                    i--;
                    c1--;
                }
            }
            else if(rl){
                ans.push_back(matrix[i][j]);
                j--;
                if(j==(c2-1)){
                    rl=false;
                    bt=true;
                    i--;
                    j++;
                    r2--;
                }
            }
            else{
                ans.push_back(matrix[i][j]);
                i--;
                if(i==(r1-1)){
                    bt=false;
                    lr=true;
                    j++;
                    i++;
                    c2++;
                }
            }
            cnt++;
        }
        return ans;
    }
};