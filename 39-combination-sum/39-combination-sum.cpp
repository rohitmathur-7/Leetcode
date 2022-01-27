class Solution {
public:
    void solve(set<vector<int> >& st,vector<int> out,int sum,int target,vector<int> arr,int idx){
        if(idx==arr.size()) return;
        if(sum>target) return;
        if(sum==target){
            st.insert(out);
            return;
        }        
        
        solve(st,out,sum,target,arr,idx+1);
        if((sum+arr[idx])<=target){
            out.push_back(arr[idx]);
            solve(st,out,sum+arr[idx],target,arr,idx);
            solve(st,out,sum+arr[idx],target,arr,idx+1);
        }
        
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> out;
        int sum=0;
        set<vector<int> > st;
        solve(st,out,sum,target,arr,0);
        for(auto x:st) ans.push_back(x);
        return ans;
    }
};