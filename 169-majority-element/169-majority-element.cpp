class Solution {
public:
    int majorityElement(vector<int>& nums){
        //Boyer-Moore algorithm
        int mj=nums[0];
        int cnt=1;
        for(int i=1;i<nums.size();i++){
            if(cnt==0){
                cnt=1;
                mj=nums[i];
            }
            else if(nums[i]==mj) cnt++;
            else cnt--;
        }
        return mj;
    }
};