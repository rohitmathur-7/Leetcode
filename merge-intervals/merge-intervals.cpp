class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int> > res;
        res.push_back(intervals[0]);
        int j=0;
        for(int i=0;i<n;i++){
            //it means they can be merged
            if(res[j][1]>=intervals[i][0]){
                res[j][1]=max(res[j][1],intervals[i][1]);
            }
            else{
                j++;
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};