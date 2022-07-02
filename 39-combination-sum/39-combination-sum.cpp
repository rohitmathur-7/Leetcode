class Solution {
public:
    void solve(int idx,int sum,vector<int> arr,int target,vector<int> ds,vector<vector<int> > &ans){
        if(sum>target) return;
        if(sum==target){
            ans.push_back(ds);
            return;
        }
        
        for(int i=idx;i<arr.size();i++){
            ds.push_back(arr[i]);
            solve(i,sum+arr[i],arr,target,ds,ans);
            ds.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int> > ans;
        sort(arr.begin(),arr.end());
        vector<int> ds;
        solve(0,0,arr,target,ds,ans);
        return ans;
    }
};