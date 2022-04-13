class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int m=n;
        vector<vector<int>> ans(n,vector<int>(n));
        int r1=0,c1=m-1,r2=n-1,c2=0,cnt=1;
        bool lr=true,tb=false,rl=false,bt=false;
        int i=0,j=0;
        while(cnt<=(n*n)){
            if(lr){
                ans[i][j]=cnt;
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
                ans[i][j]=cnt;
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
                ans[i][j]=cnt;
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
                ans[i][j]=cnt;
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