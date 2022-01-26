class Solution {
public:
    void solve(set<vector<int> >& st,vector<int> out,vector<int> arr){
        if(arr.size()==0){
            st.insert(out);
            return;
        }
        vector<int> out1=out;
        vector<int> out2=out;
        out1.push_back(arr[0]);
        arr.erase(arr.begin()+0);
        solve(st,out1,arr);
        solve(st,out2,arr);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> out;
        set<vector<int> > st;
        sort(nums.begin(),nums.end());
        solve(st,out,nums);
        for(auto x:st) ans.push_back(x);
        return ans;
    }
};