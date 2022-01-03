class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end()); 
        // for(auto x:intervals){
        //     for(auto y:x) cout<<y<<" ";
        //     cout<<endl;
        // }
        int n=intervals.size();
        int l=0,r=0;
        vector<vector<int>> ans;
        bool g=false;
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=intervals[r][1]){
                if(intervals[i][1]>=intervals[r][1]) r=i;
                // else r=l;
                if(i==n-1){
                    vector<int> tmp;
                    tmp.push_back(intervals[l][0]);
                    tmp.push_back(intervals[r][1]);
                    ans.push_back(tmp);
                    g=true;
                    // cout<<"caled"<<endl;
                    // cout<<"r: "<<r<<endl;
                }
            }
            else{
                vector<int> tmp;
            
                tmp.push_back(intervals[l][0]);
                tmp.push_back(intervals[r][1]);
                ans.push_back(tmp);
                l=i;
                r=i;
            }
        }
        if(!g){
            vector<int> tmp;
            tmp.push_back(intervals[n-1][0]);
            tmp.push_back(intervals[n-1][1]);
            ans.push_back(tmp);
        }
        
        return ans;
    }
};