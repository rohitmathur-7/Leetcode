class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
        vector<int> ans(nums1.size());
        stack<int> s;
        unordered_map<int,int> m;
        for(int i=0;i<nums1.size();i++){
            m[nums1[i]]=i;
        }
        for(auto x:m) cout<<x.first<<" "<<x.second<<endl;
        for(int i=nums2.size()-1;i>=0;i--){
            if(s.empty()){
                if(m.count(nums2[i])){
                    ans[m[nums2[i]]]=-1;
                }
            }
            else{
                while(!s.empty() && nums2[i]>=s.top()){
                    s.pop();
                }
                if(m.count(nums2[i])){
                    // cout<<"nm: "<<nums2[i]<<endl;
                    if(!s.empty()) ans[m[nums2[i]]]=s.top();
                    else{
                        ans[m[nums2[i]]]=-1;
                    }
                }
            }   
            s.push(nums2[i]);
        }
        return ans;
    }
};