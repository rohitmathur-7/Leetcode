class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        int target=0;
        sort(nums.begin(),nums.end());
        set<vector<int>> st;
        for(int i=0;i<n;i++){
            int new_target=target-nums[i];
            unordered_map<int,int> mp;
            int a=i+1,b=n-1;
            while(a<b){
                int s=nums[a]+nums[b];
                if(s<new_target) a++;
                else if(s>new_target) b--;
                else{
                    vector<int> tmp(3);
                    tmp[0]=nums[i];
                    tmp[1]=nums[a];
                    tmp[2]=nums[b];
                    sort(tmp.begin(),tmp.end());
                    st.insert(tmp);
                    while(a<b && nums[a]==tmp[1]){
                        a++;
                    }
                    while(b>a && nums[b]==tmp[2]){
                        b--;
                    }
                }
            } 
            
            while(i+1<n && nums[i]==nums[i+1]) i++;
     
        }
        
        for(auto x:st){
            ans.push_back(x);
        }
        
        return ans;
    }
};