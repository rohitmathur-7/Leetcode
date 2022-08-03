class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums){
        int cnt=0,ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                cnt++;
                if(i==nums.size()-1) ans=max(ans,cnt);
            }
            else{
                ans=max(ans,cnt);
                cnt=0;
            }
        }
        return ans;
    }
};