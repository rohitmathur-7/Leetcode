class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        set<pair<int,int> > s;
        unordered_map<int,int> m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        for(int i=0;i<n;i++){
            if(m[nums[i]+k]){
                if(nums[i]==(nums[i]+k)){
                    if(m[nums[i]]>1){
                        pair<int,int> p;
                        if(nums[i]>=(nums[i]+k)){
                            p.first=nums[i];
                            p.second=nums[i]+k;
                        }
                        else{
                            p.first=nums[i]+k;
                            p.second=nums[i];        
                        }
                        s.insert(p);    
                    }
                }
                else{
                    pair<int,int> p;
                    if(nums[i]>=(nums[i]+k)){
                        p.first=nums[i];
                        p.second=nums[i]+k;
                    }
                    else{
                        p.first=nums[i]+k;
                        p.second=nums[i];        
                    }
                    s.insert(p);
                }    
            }
        }
        return s.size();
    }
};