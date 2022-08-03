class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int a=0;
        int i;
        for(i=0;i<nums.size();i++){
            if(a==nums.size()-1){
                nums[i]=nums[a];
                break;
            }
            while(nums[a]==nums[a+1]){
                a++;
                if(a==nums.size()-1){
                    break;
                }
            }
            if(a==nums.size()-1){
                nums[i]=nums[a];
                break;
            }
            nums[i]=nums[a];
            a++;
        }
        return i+1;
    }
};