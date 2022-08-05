class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> mp1,mp2;
        for(auto x:nums1){
            mp1[x]++;    
        }
        for(auto x:nums2){
            mp2[x]++;
        }
        
        for(auto x:mp1){
            for(int i=0;i<min(x.second,mp2[x.first]);i++) ans.push_back(x.first);
        }
        return ans;
    }
};