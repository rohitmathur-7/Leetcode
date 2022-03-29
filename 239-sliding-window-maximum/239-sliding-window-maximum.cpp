class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>> dq;
        int n=nums.size();
        int cnt=k-1;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(dq.empty()){
                dq.push_back({nums[i],i});
                if(i>=cnt){
                    ans.push_back(nums[i]);
                    cnt++;
                }
            }
            else{
                int d=i-k+1;
                while(!dq.empty() && dq.front().second<d){
                    dq.pop_front();
                }
                while(!dq.empty() && dq.back().first<=nums[i]){
                    dq.pop_back();
                }
                if(dq.empty()){
                    dq.push_back({nums[i],i});
                    if(i>=cnt){
                        // ans[cnt]=nums[i];
                        ans.push_back(nums[i]);
                        cnt++;
                    }
                }
                else{
                    dq.push_back({nums[i],i});
                    if(i>=cnt){
                        // ans[cnt]=dq.front().first;
                        ans.push_back(dq.front().first);
                        cnt++;
                    }
                }
            }
        }
        return ans;
    }
};