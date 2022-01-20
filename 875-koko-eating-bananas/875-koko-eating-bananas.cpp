class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int hg=*max_element(piles.begin(),piles.end());
        int l=1,mid,ans=INT_MAX;
        while(l<hg){
            mid=l+(hg-l)/2;
            // cout<<"low: "<<l<<" high: "<<hg<<" mid: "<<mid<<endl;
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=ceil((double)piles[i]/mid);
            }
            if(sum<=h){
                hg=mid;
                ans=min(ans,mid);
                // cout<<"sum: "<<sum<<" ans: "<<ans<<endl;
            }
            else l=mid+1;
        }
        
        if(ans==INT_MAX) return l;
        return ans;
    }
};