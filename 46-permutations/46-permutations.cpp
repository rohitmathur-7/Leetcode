class Solution {
public:
    void solve(vector<vector<int>>& ans,vector<int> arr,int idx){
        if(idx==arr.size()){
            ans.push_back(arr);
        }
        for(int i=idx;i<arr.size();i++){
            swap(arr[i],arr[idx]);
            solve(ans,arr,idx+1);
            swap(arr[i],arr[idx]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& arr) {
        vector<vector<int>> ans;
        solve(ans,arr,0);
        return ans;
    }
};