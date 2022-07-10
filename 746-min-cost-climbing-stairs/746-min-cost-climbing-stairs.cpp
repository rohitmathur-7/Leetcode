class Solution {
public:
    
    int minCostClimbingStairs(vector<int>& cost){
        int n=cost.size();
        int first=cost[0];
        int second=cost[1];
        
        int cur;
        for(int i=2;i<n;i++){
            cur=cost[i]+min(first,second);
            first=second;
            second=cur;
        }
        
        return min(first,second);
    }
    
};