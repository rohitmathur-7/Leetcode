class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> m;
        int n=time.size();
        for(int i=0;i<n;i++){
            m[time[i]%60]++;
        }
        int ans=0;
        ans+=(m[0]*(m[0]-1))/2;
        ans+=(m[30]*(m[30]-1))/2;
        for(int i=1;i<=29;i++){
            ans+=m[i]*m[60-i];
        }
        return ans;
    }
};