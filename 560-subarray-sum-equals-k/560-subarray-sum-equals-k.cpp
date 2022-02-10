class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> m;
        int cur=0,ans=0;
        m[0]++;
        for(int i=0;i<n;i++){
            cur+=nums[i];
            ans+=m[cur-k];
            m[cur]++;
        }
        return ans;
    }
};