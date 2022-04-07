class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        while(stones.size()>=1){
            if(stones.size()==1) return stones[0];
            sort(stones.begin(),stones.end());
            int sze=stones.size();
            if(stones[sze-1]==stones[sze-2]){
                stones.erase(stones.begin()+sze-1);
                stones.erase(stones.begin()+sze-2);
            }
            else{
                int d=stones[sze-1]-stones[sze-2];
                stones.erase(stones.begin()+sze-1);
                stones.erase(stones.begin()+sze-2);
                stones.push_back(d);
            }
        }
        return 0;
    }
};