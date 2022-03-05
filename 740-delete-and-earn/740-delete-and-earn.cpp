class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int inc=0,exc=0;
        int cnt[10001]={0};
        for(auto num:nums){
            cnt[num]++;
        }
        
        for(int i=0;i<=10000;i++){
            int ni=exc+cnt[i]*i;
            int ne=max(inc,exc);
            inc=ni;
            exc=ne;
        }
        
        return max(inc,exc);
    }
};