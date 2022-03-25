class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& arr){
        int n=arr.size();
        vector<pair<int,pair<int,int>>> v;
        for(int i=0;i<n;i++){
            int d=arr[i][0]-arr[i][1];
            pair<int,int> p;
            p.first=arr[i][0];
            p.second=arr[i][1];
            pair<int,pair<int,int>> p1;
            p1.first=d;
            p1.second=p;
            v.push_back(p1);
        }
        int ans=0,cnt=0;
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            if(cnt<(n/2)){
                ans+=v[i].second.first;
                cnt++;
            }
            else{
                ans+=v[i].second.second;
            }
        }
        return ans;
    }
};