class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int ans=n;
        sort(intervals.begin(),intervals.end());
        int l=0,h=0;
        for(int i=0;i<n;i++){
            bool g=false;
            if(i!=0){
                if(intervals[i][0]>=intervals[l][0] && intervals[i][1]<=intervals[l][1]){
                    ans--;
                    g=true;
                }
                else if(intervals[i][0]>=intervals[h][0] && intervals[i][1]<=intervals[h][1]){
                    ans--;
                    g=true;
                }
            }
            if(!g){
                for(int j=i+1;j<n;j++){
                    if(intervals[j][0]!=intervals[i][0]) break;
                    if(intervals[i][0]>=intervals[j][0] && intervals[i][1]<=intervals[j][1]){
                        ans--;
                        break;
                    }
                }
            }
            if(intervals[i][1]>intervals[h][1]){
                h=i;
            }
        }
        return ans;
    }
};