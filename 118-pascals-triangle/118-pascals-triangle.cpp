class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> tmp;
        tmp.push_back(1);
        ans.push_back(tmp);
        if(numRows==1) return ans;
        tmp.clear();
        tmp.push_back(1);
        tmp.push_back(1);
        ans.push_back(tmp);
        if(numRows==2) return ans;
        tmp.clear();
        
        numRows-=2;
        int c=1;
        while(numRows--){
            tmp.push_back(1);
            for(int i=0;i<ans[c].size();i++){
                if(i+1<ans[c].size()) tmp.push_back(ans[c][i]+ans[c][i+1]);
            }
            tmp.push_back(1);
            ans.push_back(tmp);
            tmp.clear();
            c++;
        }
        
        return ans;
    }
};