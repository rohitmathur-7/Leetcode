class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int> mp,mp1;
        int c=0;
        for(auto x:s){
            mp[x]++;
            mp1[x]=c;
            c++;
        }
        int ans=INT_MAX;
    
        for(auto x:mp){
            if(x.second==1){
                ans=min(mp1[x.first],ans);
            }
        }
        
        return ans==INT_MAX?-1:ans;
    }
};