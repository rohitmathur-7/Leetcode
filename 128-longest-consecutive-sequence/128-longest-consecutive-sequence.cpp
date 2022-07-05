class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        nums.resize(unique(nums.begin(),nums.end()) - nums.begin());
        int n=nums.size();
        if(n==0) return 0;
        
        int ans=1,c=1;
        // for(int i=0;i<n;i++) cout<<nums[i]<<" ";
        // cout<<endl;
        for(int i=1;i<n;i++){
            if(nums[i]==(nums[i-1]+1)){
                c++;
                if(i==n-1){
                    ans=max(ans,c);
                }
            }
            else{
                ans=max(ans,c);
                c=1;
            }
        }
        
        return ans;
    }
};