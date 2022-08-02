class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size(),pos;
        vector<int> tmp(n);
        for(int i=0;i<n;i++){
            pos=(i+k)%n;
            tmp[pos]=nums[i];
        }
        for(int i=0;i<n;i++) nums[i]=tmp[i];
    }
};