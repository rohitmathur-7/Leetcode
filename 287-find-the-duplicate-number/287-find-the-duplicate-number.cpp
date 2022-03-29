class Solution {
public:
    int findDuplicate(vector<int>& nums){
        int n=nums.size();
        int ans=0;
        int pre[64],arr[64];
        for(int i=0;i<64;i++){
            pre[i]=0,arr[i]=0;
        }
        int tmp,cnt;
        for(int i=1;i<n;i++){
            tmp=i,cnt=0;
            while(tmp){
                if(tmp&1){
                    pre[cnt]++;
                }
                tmp>>=1;
                cnt++;
            }
        }
        for(int i=0;i<n;i++){
            tmp=nums[i],cnt=0;
            while(tmp){
                if(tmp&1){
                    arr[cnt]++;
                }
                tmp>>=1;
                cnt++;
            }
        }
        for(int i=0;i<64;i++){
            if(arr[i]>pre[i]) ans+=pow(2,i);
        }
        return ans;
    }
};