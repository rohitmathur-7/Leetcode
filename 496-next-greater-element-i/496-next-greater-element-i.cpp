class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
        int n=nums1.size(),m=nums2.size();
        stack<int> st;
        vector<int> ans(n);
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums1[i]]=i;
        }
        for(int i=m-1;i>=0;i--){
            if(st.empty()){
                st.push(nums2[i]);
                if(mp.count(nums2[i])){
                    ans[mp[nums2[i]]]=-1;
                }
            }
            else{
                while(!st.empty() && st.top()<=nums2[i]){
                    st.pop();
                }
                if(!st.empty()){
                    if(mp.count(nums2[i])){
                        ans[mp[nums2[i]]]=st.top();
                    }
                }
                else{
                    if(mp.count(nums2[i])){
                        ans[mp[nums2[i]]]=-1;
                    }
                }
                st.push(nums2[i]);
            }
        }
        return ans;
    }
};