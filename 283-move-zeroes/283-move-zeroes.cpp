class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int a=0,b;
        while(a<nums.size() && nums[a]!=0) a++;
        if(a<nums.size()-1) b=a+1;
        else return;
        while(b<nums.size()){
            if(nums[b]!=0){
                swap(nums[a],nums[b]);
                a++;
            }
            b++;
        }
    }
};