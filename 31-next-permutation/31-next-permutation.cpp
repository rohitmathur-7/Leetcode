class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        
        int k=-1,pos=-1;
        for(int i=0;i<n;i++){
            if(i+1<n && nums[i]<nums[i+1]){
                pos=i;
            }
        }
        
        if(pos==-1){
            reverse(nums.begin(),nums.end());
        }
        else{
            int l;
            for(int i=n-1;i>k;i--){
                if(nums[i]>nums[pos]){
                    l=i;
                    break;
                }
            }
            
            swap(nums[pos],nums[l]);
            reverse(nums.begin()+pos+1,nums.end());
        }
        
    }
};