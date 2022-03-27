class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& arr, int k) {
        int n=arr.size();
        int m=arr[0].size();
        vector<pair<int,int> > ans;
        for(int i=0;i<n;i++){
            int one=0;
            for(int j=0;j<m;j++){
                if(arr[i][j]==1){
                    one++;
                }
            }
            ans.push_back({one,i});
        }
        vector<int> v;
        sort(ans.begin(),ans.end());
        for(int i=0;i<k;i++){
            v.push_back(ans[i].second);
        }
        
        return v;
    }
};