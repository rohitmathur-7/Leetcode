class Solution {
public:
    void solve(int idx,int sum,vector<int> arr,int target,vector<int> ds,vector<vector<int> > &ans){
        if(sum>target) return;
        if(sum==target){
            ans.push_back(ds);
            return;
        }
        
        for(int i=idx;i<arr.size();i++){
            if(i!=idx && arr[i]==arr[i-1]) continue;
            ds.push_back(arr[i]);
            solve(i+1,sum+arr[i],arr,target,ds,ans);
            ds.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<vector<int> > ans;
        vector<int> ds;
        sort(arr.begin(),arr.end());
        solve(0,0,arr,target,ds,ans);
        
        return ans;
    }
};