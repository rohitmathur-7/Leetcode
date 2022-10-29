class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int ans=0;
        vector<pair<int,int>> v;
        for(int i=0;i<plantTime.size();i++){
            v.push_back({growTime[i],plantTime[i]});
        }
        
        int start=0;
        sort(v.begin(),v.end(),greater<pair<int,int>>());        
        for(int i=0;i<plantTime.size();i++){
            start+=v[i].second;
            ans=max(ans,start+v[i].first);
        }
        
        return ans;
    }
};