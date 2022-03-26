class Solution {
public:
    int search(vector<int>& nums, int target){
        int n=nums.size();
        int lw=0,hg=n-1,mid;
        while(lw<=hg){
            mid=lw+(hg-lw)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target){
                lw=mid+1;
            }
            else{
                hg=mid-1;
            }
        }
        return -1;
    }
};