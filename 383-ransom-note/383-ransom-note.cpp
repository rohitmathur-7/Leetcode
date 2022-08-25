class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<int,int> mp1,mp2;
        for(auto x:ransomNote) mp1[x]++;
        for(auto x:magazine) mp2[x]++;
        
        for(auto x:mp1){
            if(x.second>mp2[x.first]) return false;
        }
        
        return true;
    }
};