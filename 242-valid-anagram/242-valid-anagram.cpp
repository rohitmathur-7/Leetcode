class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp1,mp2;
        for(auto x:s){
            mp1[x]++;
        }
        for(auto x:t){
            mp2[x]++;
        }
        
        if(mp1.size()!=mp2.size()) return false;
        
        for(auto x:mp1){
            if(mp2.find(x.first)==mp2.end()) return false;
            if(mp1[x.first]!=mp2[x.first]) return false;
        }
        for(auto x:mp2){
            if(mp1.find(x.first)==mp1.end()) return false;
        }
        
        return true;
        
    }
};