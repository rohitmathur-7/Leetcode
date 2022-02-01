class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn=INT_MAX,ans=INT_MIN;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<mn) mn=prices[i];
            ans=max(ans,prices[i]-mn);
        }
        return ans;
    }
};