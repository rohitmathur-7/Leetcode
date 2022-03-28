class Solution {
public:
    bool search(vector<int>& nums, int target) {
        map<int,int> m;
        int n=nums.size();
        for(int i=0;i<n;i++) m[nums[i]]++;
        if(m.count(target)) return true;
        return false;
    }
};